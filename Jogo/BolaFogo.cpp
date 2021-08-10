#include "stdafx.h"
#include "BolaFogo.h"

BolaFogo::BolaFogo() {}

BolaFogo::BolaFogo(sf::Vector2f posicao, bool direcao) :Projetil(posicao, direcao, "./Recursos/Imagens/Projeteis/bolafogo.png",0.25f,0.25f)
{
	dano = 50;
}

BolaFogo::~BolaFogo() {}