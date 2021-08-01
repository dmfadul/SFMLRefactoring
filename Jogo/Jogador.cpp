#include "stdafx.h"
#include "Jogador.h"

// _______________________________________________________________________________
Jogador::Jogador(){

}

// _______________________________________________________________________________
Jogador::~Jogador(){}

// _______________________________________________________________________________
void Jogador::iniciarHitbox()
{
	this->hitbox.setSprite(&this->sprite);
	this->hitbox.setTamanho(sf::Vector2f(25, 36.f ));
	this->hitbox.setOffsetX(15);
	this->hitbox.setOffSetY(25);
}

// _______________________________________________________________________________
void Jogador::iniciarCompMov()
{
	this->compMov.iniciarCompMov(&this->sprite, VEL_MAX_PLAYER);
}
