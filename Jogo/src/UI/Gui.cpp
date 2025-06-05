#include "Core/stdafx.h"
#include "UI/Gui.h"

// _______________________________________________________________________________
Gui::Gui()
{
}

// _______________________________________________________________________________
Gui::~Gui()
{
}

// _______________________________________________________________________________
void Gui::iniciarTexto(float pos_x, float pos_y, std::string texto)
{
	/* Inicia fonte e centraliza o texto no bot�o */
	if (!this->fonte.loadFromFile("../assets/Fontes/Bebas.ttf")) {
		std::cout << "BOTAO::FALHA AO CARREGAR FONTE" << std::endl;
	}

	// Inicia texto
	this->texto.setString(texto);
	this->texto.setFont(this->fonte);
	this->texto.setCharacterSize(38);
}

// _______________________________________________________________________________
void Gui::setTexto(std::string texto)
{
	this->texto.setString(texto);
}

// _______________________________________________________________________________
sf::Text* Gui::getTexto() {
	return &this->texto;
}

// _______________________________________________________________________________
void Gui::desenharGui(sf::RenderTarget& janela)
{
	janela.draw(this->texto);
}
