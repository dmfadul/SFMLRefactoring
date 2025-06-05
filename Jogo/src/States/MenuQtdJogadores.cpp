#include "Core/stdafx.h"
#include "States/MenuQtdJogadores.h"

// _______________________________________________________________________________
MenuQtdJogadores::MenuQtdJogadores()
	:Menu()
{
	this->botaoAtivo = um_jogador;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/menu_jogadores.png");
}

// _______________________________________________________________________________
MenuQtdJogadores::~MenuQtdJogadores()
{
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuQtdJogadores::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[um_jogador] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 220.f, "UM JOGADOR");
	this->botoes[dois_jogadores] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 280.f, "DOIS JOGADORES");
	this->botoes[voltar] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 430.f, "VOLTAR");

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
void MenuQtdJogadores::atualizar()
{
}

// _______________________________________________________________________________
void MenuQtdJogadores::GerenciarCliqueBotao()
{
	/* Realiza a a��o vinculada com o botao ativo */

	if (this->botaoAtivo == um_jogador) {
		JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
		JogoInfo::getInstancia()->trocarEnte(static_cast<Ente*>(new VelhoOeste(1)));
	}
	else if (this->botaoAtivo == dois_jogadores) {
		JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
		JogoInfo::getInstancia()->trocarEnte(static_cast<Ente*>(new VelhoOeste(2)));
	}
	else if (this->botaoAtivo == voltar)
		JogoInfo::getInstancia()->popEnte();
}