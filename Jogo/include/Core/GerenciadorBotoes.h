#pragma once
#include "Botao.h"
#include "JogoInfo.h"
#include "BotaoPadrao.h"
#include "BotaoSair.h"

class GerenciadorBotoes
{
protected:
	// variaveis
	std::map<int, gui::Botao* > botoes;
	BotaoPadrao builderBotaoPadrao;
	BotaoSair builderBotaoSair;
	som::TocaDisco* tocaDisco;
	int botaoAtivo;

public:
	// construtoras e destrutoras 
	GerenciadorBotoes();
	~GerenciadorBotoes();

	// Metodos de Inicialização
	virtual void iniciarBotoes();

	void trocarBotao(int direcao);
	virtual void GerenciarCliqueBotao();


};

