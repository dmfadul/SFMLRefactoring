#include "Core/stdafx.h"
#include "Entities/Shuriken.h"

// _______________________________________________________________________________
Shuriken::Shuriken()
{
}

// _______________________________________________________________________________
Shuriken::Shuriken(sf::Vector2f posicao, bool direcao)
	:Projetil(posicao, direcao, "../assets/Imagens/Projeteis/shuriken.png", 0.05f, 0.05f)
{
	this->dano = 25;
	this->atirador = "JOGADOR";
	this->nome = "SHURIKEN";
}

// _______________________________________________________________________________
Shuriken::~Shuriken()
{
}
