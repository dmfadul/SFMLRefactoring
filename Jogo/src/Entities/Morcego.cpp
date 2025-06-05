#include "Core/stdafx.h"
#include "Entities/Morcego.h"

Morcego::Morcego(){}

Morcego::Morcego(sf::Vector2f posicao, bool direcao)
	:Projetil(posicao, direcao, "./Recursos/Imagens/Projeteis/morcego.png",1.f,1.f)
{
	this->dano = 30;
	this->atirador = "INIMIGO";
	this->nome = "MORCEGO";
}

Morcego::~Morcego(){}

