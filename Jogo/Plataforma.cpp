#include "stdafx.h"
#include "Plataforma.h"

// _______________________________________________________________________________
Plataforma::Plataforma(int indice, const bool colidir)
	: Entidade(indice, colidir)
{
	this->iniciarSprite(indice);
}

// _______________________________________________________________________________
Plataforma::~Plataforma()
{
}

// _______________________________________________________________________________
void Plataforma::iniciarSprite(int indice)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/plataformas/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "ENTIDADE::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->entidade.setTexture(this->textura);
	this->entidade.setScale(0.25f, 0.25f);
}

