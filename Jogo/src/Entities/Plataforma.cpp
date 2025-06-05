#include "stdafx.h"
#include "Plataforma.h"

// _______________________________________________________________________________
Plataforma::Plataforma(int indice, const bool colidir)
	: Obstaculo(colidir)
{
	this->iniciarSprite(indice, 0.25f, 0.25f);
}

// _______________________________________________________________________________
Plataforma::~Plataforma()
{
}

// _______________________________________________________________________________
void Plataforma::iniciarSprite(int indice, float scale_x, float scale_y)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/plataformas/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "ENTIDADE::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->sprite.setTexture(this->textura);
	this->sprite.setScale(scale_x, scale_y);
}
