#include "Core/stdafx.h"
#include "States/MenuEscolhaFases.h"

// _______________________________________________________________________________
MenuEscolhaFases::MenuEscolhaFases()
	:Menu()
{
	this->botaoAtivo = velho_oeste;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/menu_fases.png");
}

// _______________________________________________________________________________
MenuEscolhaFases::~MenuEscolhaFases()
{
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuEscolhaFases::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[velho_oeste] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 220.f, "Velho Oeste");
	this->botoes[ninho_do_dragao] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 280.f, "Ninho Do Drag�o");
	this->botoes[voltar] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 430.f, "Voltar");

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300, 350.f));
	this->caixaBotoes.setPosition(
		TAM_JANELA_X / 2 - this->caixaBotoes.getGlobalBounds().width / 2,
		TAM_JANELA_Y / 2 - this->caixaBotoes.getGlobalBounds().height / 2
	);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuEscolhaFases::atualizar()
{
}

// _______________________________________________________________________________
void MenuEscolhaFases::GerenciarCliqueBotao()
{
	/* Realiza a a��o vinculada com o botao ativo */

	if (this->botaoAtivo == velho_oeste) {
		JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
		JogoInfo::getInstancia()->trocarEnte(static_cast<Ente*>(new VelhoOeste()));
	}

	else if (this->botaoAtivo == ninho_do_dragao) {
		JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
		JogoInfo::getInstancia()->trocarEnte(static_cast<Ente*>(new NinhoDoDragao()));
	}

	else if (this->botaoAtivo == voltar)
		JogoInfo::getInstancia()->popEnte();
}