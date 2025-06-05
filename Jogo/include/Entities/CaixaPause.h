#pragma once
#include "Botao.h"
#include "GerenciadorBotoes.h"

enum botoes_pause {
	continuar,
	salvar_partida,
	voltar
};
/* Classe da caixa de pause em uma fase */
class CaixaPause : public Gui, public GerenciadorBotoes
{
private:
	// variaveis
	sf::RectangleShape caixa;
	GerenciadorBotoes gerBotoes;

public:
	// construtoras e destrutoras
	CaixaPause();
	~CaixaPause();

	//metodos
	void desenharCaixaPause(sf::RenderTarget& janela);
	const int getBotaoAtivo() const;
};

