#include "stdafx.h"
#include "BolaFogo.h"

// _______________________________________________________________________________
BolaFogo::BolaFogo() {}

// _______________________________________________________________________________
BolaFogo::BolaFogo(sf::Vector2f posicao, bool direcao) :Projetil(posicao, direcao, "./Recursos/Imagens/Projeteis/bolafogo.png",0.25f,0.25f)
{
	this->dano = 50;
	this->atirador = "INIMIGO";
	this->nome = "BOLA_DE_FOGO";
}

// _______________________________________________________________________________
BolaFogo::~BolaFogo() {}