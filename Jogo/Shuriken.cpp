#include "stdafx.h"
#include "Shuriken.h"

Shuriken::Shuriken()
{
}

Shuriken::Shuriken(sf::Vector2f posicao, bool direcao)
	:Projetil(posicao, direcao, "./Recursos/Imagens/Projeteis/shuriken.png", 0.05f, 0.05f)
{
	this->dano = 500;
	this->atirador = "JOGADOR";
}

Shuriken::~Shuriken()
{
}
