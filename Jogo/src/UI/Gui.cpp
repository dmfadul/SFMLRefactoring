#include "stdafx.h"
#include "Gui.h"

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
	/* Inicia fonte e centraliza o texto no botão */
	if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")) {
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
