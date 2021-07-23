#include "stdafx.h"
#include "Entidade.h"

// _______________________________________________________________________________
Entidade::Entidade(int indice,const bool colidir)
{
	this->colidir = colidir;
}

// _______________________________________________________________________________
Entidade::~Entidade()
{
}


// _______________________________________________________________________________
const bool Entidade::getColidir() const
{
	return this->colidir;
}

// _______________________________________________________________________________
void Entidade::setPosicao(const float x, const float y)
{
	this->entidade.setPosition(x, y);
}

// _______________________________________________________________________________
void Entidade::desenharEntidade(sf::RenderTarget& janela)
{
	janela.draw(this->entidade);
}
