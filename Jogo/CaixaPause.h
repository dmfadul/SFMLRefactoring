#pragma once
#include "Botao.h"
#include "GerenciadorBotoes.h"

enum botoes_pause {
	continuar,
	salvar_partida,
	voltar
};

class CaixaPause : public Gui, public GerenciadorBotoes
{
private:
	sf::RectangleShape caixa;
	GerenciadorBotoes gerBotoes;

public:
	CaixaPause();
	~CaixaPause();

	void desenharCaixaPause(sf::RenderTarget& janela);
	const int getBotaoAtivo() const;
};

