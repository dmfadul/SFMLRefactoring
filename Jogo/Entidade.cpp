#include "stdafx.h"
#include "Entidade.h"

int Entidade::qtdEntidades = 0;

// _______________________________________________________________________________
Entidade::Entidade()
{
	this->id = qtdEntidades++;
}

// _______________________________________________________________________________
Entidade::~Entidade()
{
}

void Entidade::atualizar()
{
}

void Entidade::desenhar(sf::RenderTarget& janela)
{
}

const int Entidade::getId() const
{
	return this->id;
}

