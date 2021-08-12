#include "stdafx.h"
#include "Entidade.h"

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

const std::string Entidade::getNome() const
{
	return this->nome;
}

