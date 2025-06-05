#include "Core/stdafx.h"
#include "Entities/Entidade.h"

int Entidade::qtdEntidades = 0;

// _______________________________________________________________________________
Entidade::Entidade()
{
	this->id = qtdEntidades++;
	this->nome = "";
}

// _______________________________________________________________________________
Entidade::~Entidade()
{
}

// _______________________________________________________________________________
const int Entidade::getId() const { return this->id; }

const std::string Entidade::getNome() const { return this->nome; }

