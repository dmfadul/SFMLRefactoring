#include "stdafx.h"
#include "Personagem.h"

Personagem::Personagem():
hp(100),
dano(100),
hitbox(){}

Personagem::~Personagem(){}

int Personagem::getHP() const
{
	return hp;
}

void Personagem::setHP(int h)
{
	hp = h;
}

int Personagem::getDano() const
{
	return dano;
}

void Personagem::setDano(int d)
{
	dano = d;
}
