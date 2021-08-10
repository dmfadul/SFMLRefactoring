#include "stdafx.h"
#include "Morcego.h"

Morcego::Morcego(){}

Morcego::Morcego(sf::Vector2f posicao, bool direcao):Projetil(posicao, direcao, "./Recursos/Imagens/Projeteis/morcego.png",1.f,1.f)
{
	dano = 30;
}

Morcego::~Morcego(){}

