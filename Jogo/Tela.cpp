#include "stdafx.h"
#include "Tela.h"

// _______________________________________________________________________________
Tela::Tela(JogoInfo* pji)
{
	this->jogoInfo = pji;
}

// _______________________________________________________________________________
Tela::~Tela()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void Tela::iniciarBackground(std::string diretorio)
{
	/* carrega imagem do background */
	if (!this->textura.loadFromFile(diretorio)) {
		std::cout << "ENTE::FALHA AO CARREGAR BACKGROUND" << std::endl;
	}
	this->sprite.setTexture(this->textura);
}