#include "stdafx.h"
#include "GerenciadorBotoes.h"

GerenciadorBotoes::GerenciadorBotoes()
	: tocaDisco(new TocaDisco())
{
	this->botaoAtivo = 0;
}

GerenciadorBotoes::~GerenciadorBotoes()
{
	delete this->tocaDisco;
	for (auto& botao : this->botoes) {
		botao.second = NULL;
	}
	this->botoes.clear();
}


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

void GerenciadorBotoes::GerenciarCliqueBotao()
{
}
