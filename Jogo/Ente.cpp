#include "stdafx.h"
#include "Ente.h"

// _______________________________________________________________________________
Ente::Ente() 
{ 
	this->enteInfo = NULL;
}

// _______________________________________________________________________________
Ente::Ente(EnteInfo* pei)
{
	this->enteInfo = pei;
}

// _______________________________________________________________________________
Ente::~Ente()
{
	this->enteInfo = NULL;
}

// _______________________________________________________________________________
void Ente::iniciarBackground(std::string diretorio)
{
	/* carrega imagem do background */
	if (!this->texturaBg.loadFromFile(diretorio)) {
		std::cout << "ENTE::FALHA AO CARREGAR BACKGROUND" << std::endl;
	}
	this->background.setTexture(this->texturaBg);
}

// _______________________________________________________________________________
const bool Ente::getEncerrar() const
{
	return this->enteInfo->encerrarEnte;
}

// _______________________________________________________________________________
void Ente::setEncerrar(const bool e)
{
	this->enteInfo->encerrarEnte = e;
}
