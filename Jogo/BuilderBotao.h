#pragma once
#include "Botao.h"

class BuilderBotao
{
protected:
	// variaveis
	gui::Botao* botao;
	sf::Font fonte;

	// metodos de construção
	virtual void buildTexto(int tam_char, std::string fontDir, std::string texto);
	virtual void buildCaixa(float pos_x, float pos_y, sf::Vector2f tam);
	virtual void buildCores(sf::Color ativado, sf::Color desativado, sf::Color cor_caixa);

public:
	// construtoras e destrutoras
	BuilderBotao();
	~BuilderBotao();

	virtual gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto) = 0;
};

