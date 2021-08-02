#include "stdafx.h"
#include "Gui.h"

Gui::Gui()
{
}

Gui::~Gui()
{
}

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
