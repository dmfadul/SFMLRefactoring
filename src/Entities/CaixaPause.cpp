#include "Core/stdafx.h"
#include "configuracoes.h"
#include "Entities/CaixaPause.h"

// _______________________________________________________________________________
CaixaPause::CaixaPause()
{
	this->iniciarTexto(0, 0, "PAUSE");
	this->caixa.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixa.setSize(sf::Vector2f((float)(TAM_JANELA_X / 2), 320.f));
	this->caixa.setPosition(
		TAM_JANELA_X / 2 - this->caixa.getGlobalBounds().width / 2,
		TAM_JANELA_Y / 2 - this->caixa.getGlobalBounds().height / 2
	);
	
	this->texto.setPosition(
		TAM_JANELA_X / 2 - this->texto.getGlobalBounds().width / 2,
		this->caixa.getPosition().y + 10.f
	);

	/* Inicia todos os botoes da caixa de pause */
	this->botoes[continuar] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, this->caixa.getPosition().y + 80.f, "continuar jogo");
	this->botoes[salvar_partida] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, this->caixa.getPosition().y + 140.f, "salvar partida atual");
	this->botoes[voltar] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, this->caixa.getPosition().y + 200.f, "voltar ao menu principal");

	this->botaoAtivo = continuar;
	this->botoes[botaoAtivo]->ativar();
}

// _______________________________________________________________________________
CaixaPause::~CaixaPause()
{
}

// _______________________________________________________________________________
void CaixaPause::desenharCaixaPause(sf::RenderTarget& janela)
{
	janela.draw(this->caixa);
	janela.draw(this->texto);

	// desenha botoes
	for (auto& botao : this->botoes)
		botao.second->desenharBotao(janela);
}

// _______________________________________________________________________________
const int CaixaPause::getBotaoAtivo() const
{
	return this->botaoAtivo;
}
