#pragma once
#include "Botao.h"
#include "JogoInfo.h"

class GerenciadorBotoes
{
protected:
	std::map<int, gui::Botao* > botoes;
	TocaDisco* tocaDisco;
	int botaoAtivo;

public:
	GerenciadorBotoes();
	~GerenciadorBotoes();

	// Metodos de Inicialização
	virtual void iniciarBotoes();

	void trocarBotao(int direcao);
	virtual void GerenciarCliqueBotao();


};

