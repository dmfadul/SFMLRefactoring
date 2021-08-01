#include "stdafx.h"
#include "Personagem.h"

int Personagem::qtdPersonagens = 0;

// _______________________________________________________________________________
Personagem::Personagem():
hp(100),
dano(100),
hitbox(),
id(qtdPersonagens++){}

// _______________________________________________________________________________
Personagem::~Personagem(){}

// _______________________________________________________________________________
void Personagem::setHP(int h) { this->hp = h; }

void Personagem::setDano(int d) { this->dano = d; }

void Personagem::setPosicao(const float x, const float y) { this->sprite.setPosition(x,y); }

// _______________________________________________________________________________
const int Personagem::getId() const { return this->id; }

const int Personagem::getHP() const { return this->hp; }

const int Personagem::getDano() const { return this->dano; }

sf::FloatRect Personagem::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Personagem::getPosition() const {  return this->sprite.getPosition(); }


// _______________________________________________________________________________
HitBox Personagem::getHitbox() const { return this->hitbox; }

ComponenteMovimento* Personagem::getMovComp() { return &this->compMov; }
