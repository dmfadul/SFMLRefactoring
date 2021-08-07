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
	try {
		this->textura.loadFromFile(diretorio);
	}
	catch (...){
		std::cerr << "TELA::INICIARBACKGROUND FALHA AO INICIAR BACKGROUND" <<
			diretorio << std::endl;
		std::exit(EXIT_FAILURE);
	}
	this->sprite.setTexture(this->textura);
}