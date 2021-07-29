#include "stdafx.h"
#include "Jogador.h"

Jogador::Jogador(){

}


Jogador::~Jogador(){}

void Jogador::iniciarHitbox()
{
	this->hitbox.setSprite(&this->sprite);
	this->hitbox.setTamanho(sf::Vector2f(25.f, 35.f));
	this->hitbox.setOffsetX(15);
	this->hitbox.setOffSetY(25);
}
