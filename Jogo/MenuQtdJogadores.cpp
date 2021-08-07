#include "stdafx.h"
#include "MenuQtdJogadores.h"

// _______________________________________________________________________________
MenuQtdJogadores::MenuQtdJogadores(JogoInfo* pji)
	:Menu(pji)
{
	this->botaoAtivo = um_jogador;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/menu_jogadores.png");
}

// _______________________________________________________________________________
MenuQtdJogadores::~MenuQtdJogadores()
{
	this->jogoInfo = NULL;
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuQtdJogadores::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[um_jogador] = new gui::Botao(TAM_JANELA_X / 2 - 100.f, 220.f, "UM JOGADOR");
	this->botoes[dois_jogadores] = new gui::Botao(TAM_JANELA_X / 2 - 100.f, 280.f, "DOIS JOGADORES");
	this->botoes[voltar] = new gui::Botao(TAM_JANELA_X / 2 - 100.f, 430.f, "Voltar");

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
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == um_jogador) {
		this->jogoInfo->getTocaDisco()->pararMusica();
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo, 1)));
	}
	else if (this->botaoAtivo == dois_jogadores) {
		this->jogoInfo->getTocaDisco()->pararMusica();
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo, 2)));
	}
	else if (this->botaoAtivo == voltar)
		this->jogoInfo->popEnte();
}