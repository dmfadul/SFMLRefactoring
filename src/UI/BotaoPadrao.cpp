#include "Core/stdafx.h"
#include "UI/BotaoPadrao.h"

// _______________________________________________________________________________
BotaoPadrao::BotaoPadrao()
{
}

// _______________________________________________________________________________
BotaoPadrao::~BotaoPadrao()
{
}

// _______________________________________________________________________________
gui::Botao* BotaoPadrao::criarBotao(float pos_x, float pos_y, std::string texto)
{
	this->botao = new gui::Botao();
	this->buildTexto(38, "../assets/Fontes/Bebas.ttf", texto);
	this->buildCaixa(pos_x, pos_y, sf::Vector2f(200.f, 50.f));
	this->buildCores(sf::Color::White, sf::Color(150, 150, 150), sf::Color::Transparent);
	return this->botao;
}
