#include "stdafx.h"
#include "MenuEscolhaFases.h"

// _______________________________________________________________________________
MenuEscolhaFases::MenuEscolhaFases(JogoInfo* pji)
	:Menu(pji)
{
	this->botaoAtivo = velho_oeste;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/bg.png");
}

// _______________________________________________________________________________
MenuEscolhaFases::~MenuEscolhaFases()
{
	this->jogoInfo = NULL;
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuEscolhaFases::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[velho_oeste] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 200.f, "Velho Oeste");
	this->botoes[ninho_do_dragao] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 260.f, "Ninho Do Dragão");
	this->botoes[voltar] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 380.f, "Voltar");

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300.f, 270.f));
	this->caixaBotoes.setPosition(this->jogoInfo->getTamJanela().x / 2 - this->caixaBotoes.getGlobalBounds().width / 2, 180.f);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuEscolhaFases::atualizar()
{
}

// _______________________________________________________________________________
void MenuEscolhaFases::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == velho_oeste)
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo)));

	else if (this->botaoAtivo == ninho_do_dragao)
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new NinhoDoDragao(this->jogoInfo)));

	else if (this->botaoAtivo == voltar)
		this->jogoInfo->popEnte();
}