#include "Core/stdafx.h"
#include "Entities/Ente.h"

// _______________________________________________________________________________
Ente::Ente()
{
}

// _______________________________________________________________________________
Ente::~Ente()
{
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