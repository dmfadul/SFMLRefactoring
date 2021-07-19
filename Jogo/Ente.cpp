#include "stdafx.h"
#include "Ente.h"

// _______________________________________________________________________________
Ente::Ente() 
{ 
	this->jogoInfo = NULL;
}

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
	if (!this->texturaBg.loadFromFile(diretorio)) {
		std::cout << "ENTE::FALHA AO CARREGAR BACKGROUND" << std::endl;
	}
	this->background.setTexture(this->texturaBg);
}

// _______________________________________________________________________________
const bool Ente::getEncerrar() const
{
	return this->jogoInfo->getEncerrarEnte();
}

// _______________________________________________________________________________
void Ente::setEncerrar(const bool e)
{
	this->jogoInfo->setEncerrarEnte(e);
}
