#include "stdafx.h"
#include "Ente.h"

// _______________________________________________________________________________
Ente::Ente(JogoInfo* pji)
{
	this->jogoInfo = pji;
}

// _______________________________________________________________________________
Ente::~Ente()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void Ente::iniciarBackground(std::string diretorio)
{
	/* carrega imagem do background */
	try {
		this->textura.loadFromFile(diretorio);
	}
	catch (...){
		std::cerr << "ENTE::INICIARBACKGROUND FALHA AO INICIAR BACKGROUND" <<
			diretorio << std::endl;
		std::exit(EXIT_FAILURE);
	}
	this->sprite.setTexture(this->textura);
}