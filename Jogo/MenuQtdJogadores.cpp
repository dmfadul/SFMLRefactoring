#include "stdafx.h"
#include "MenuQtdJogadores.h"

MenuQtdJogadores::MenuQtdJogadores(JogoInfo* pji)
	:Menu(pji)
{
	this->botaoAtivo = um_jogador;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/bg.png");
}

MenuQtdJogadores::~MenuQtdJogadores()
{
	this->jogoInfo = NULL;
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

void MenuQtdJogadores::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[um_jogador] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 200.f, "UM JOGADOR");
	this->botoes[dois_jogadores] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 260.f, "DOIS JOGADORES");
	this->botoes[voltar] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 380.f, "Voltar");

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300.f, 270.f));
	this->caixaBotoes.setPosition(this->jogoInfo->getTamJanela().x / 2 - this->caixaBotoes.getGlobalBounds().width / 2, 180.f);

	this->botoes[this->botaoAtivo]->ativar();
}

void MenuQtdJogadores::atualizar()
{
}

void MenuQtdJogadores::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == um_jogador || this->botaoAtivo == dois_jogadores)
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo)));

	else if (this->botaoAtivo == voltar)
		this->jogoInfo->popEnte();
}