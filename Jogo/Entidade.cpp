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

const int Entidade::getId() const
{
	return this->id;
}

