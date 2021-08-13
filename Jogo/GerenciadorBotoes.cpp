#include "stdafx.h"
#include "GerenciadorBotoes.h"

// _______________________________________________________________________________
GerenciadorBotoes::GerenciadorBotoes()
	: tocaDisco(new som::TocaDisco())
{
	this->botaoAtivo = 0;
}

// _______________________________________________________________________________
GerenciadorBotoes::~GerenciadorBotoes()
{
	delete this->tocaDisco;
	for (auto& botao : this->botoes) {
		botao.second = NULL;
	}
	this->botoes.clear();
}

// _______________________________________________________________________________
void GerenciadorBotoes::iniciarBotoes()
{
}

// _______________________________________________________________________________
void GerenciadorBotoes::trocarBotao(int direcao)
{
	/* Muda o botao ativo */

	// toca som de troca de botao
	this->tocaDisco->tocarTrocaBotao();

	// desativa o botao atual
	this->botoes[this->botaoAtivo]->desativar();

	// troca o botao ativo
	if (this->botaoAtivo + direcao >= 0)
		this->botaoAtivo = (this->botaoAtivo + direcao) % static_cast<int>(this->botoes.size());
	else
		this->botaoAtivo = static_cast<int>(this->botoes.size()) - 1;

	// ativa o novo botao atual
	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void GerenciadorBotoes::GerenciarCliqueBotao()
{
}
