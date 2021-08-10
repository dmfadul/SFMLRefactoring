#include "stdafx.h"
#include "Morcego.h"

Morcego::Morcego(){}

Morcego::Morcego(int indice, sf::Vector2f posicao, bool direcao):Projetil(indice, posicao, direcao)
{
	this->iniciarSprite(indice);
	dano = 30;
}

Morcego::~Morcego(){}

