#pragma once
#include "UI/Botao.h"
#include "Utils/JogoInfo.h"
#include "UI/BotaoPadrao.h"
#include "UI/BotaoSair.h"

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

	// Metodos de Inicializa��o
	virtual void iniciarBotoes();

	void trocarBotao(int direcao);
	virtual void GerenciarCliqueBotao();


};

