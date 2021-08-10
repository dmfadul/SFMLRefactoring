#pragma once
#include "Botao.h"

class BuilderBotao
{
protected:
	gui::Botao* botao;
	sf::Font fonte;

	virtual void buildTexto(int tam_char, std::string fontDir, std::string texto);
	virtual void buildCaixa(float pos_x, float pos_y, sf::Vector2f tam);
	virtual void buildCores(sf::Color ativado, sf::Color desativado, sf::Color cor_caixa);

public:
	BuilderBotao();
	~BuilderBotao();

	virtual gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto) = 0;
};

