#include "Core/stdafx.h"
#include "BotaoSair.h"

// _______________________________________________________________________________
BotaoSair::BotaoSair()
{
}

// _______________________________________________________________________________
BotaoSair::~BotaoSair()
{
}

// _______________________________________________________________________________
gui::Botao* BotaoSair::criarBotao(float pos_x, float pos_y, std::string texto)
{
	this->botao = new gui::Botao();
	this->buildTexto(38, "./Recursos/Fontes/Bebas.ttf", texto);
	this->buildCaixa(pos_x, pos_y, sf::Vector2f(200.f, 50.f));
	this->buildCores(sf::Color::Red, sf::Color(150, 150, 150), sf::Color::Transparent);
	return this->botao;
}
