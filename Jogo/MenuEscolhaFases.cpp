#include "stdafx.h"
#include "MenuEscolhaFases.h"

// _______________________________________________________________________________
MenuEscolhaFases::MenuEscolhaFases(JogoInfo* pji)
	:Menu(pji)
{
	this->botaoAtivo = velho_oeste;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/menu_fases.png");
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
	this->botoes[velho_oeste] = new gui::Botao(TAM_JANELA_X / 2 - 100.f, 220.f, "Velho Oeste");
	this->botoes[ninho_do_dragao] = new gui::Botao(TAM_JANELA_X / 2 - 100.f, 280.f, "Ninho Do Dragão");
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
void MenuEscolhaFases::atualizar()
{
}

// _______________________________________________________________________________
void MenuEscolhaFases::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == velho_oeste) {
		this->jogoInfo->getTocaDisco()->pararMusica();
		this->jogoInfo->trocarTela(static_cast<Tela*>(new VelhoOeste(this->jogoInfo)));
	}

	else if (this->botaoAtivo == ninho_do_dragao) {
		this->jogoInfo->getTocaDisco()->pararMusica();
		this->jogoInfo->trocarTela(static_cast<Tela*>(new NinhoDoDragao(this->jogoInfo)));
	}

	else if (this->botaoAtivo == voltar)
		this->jogoInfo->popTela();
}