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

sf::Vector2f Personagem::getPosition() const {  return this->sprite.getPosition(); }

// _______________________________________________________________________________
sf::Vector2i Personagem::getPosGrid() const { 
	return sf::Vector2i(
		this->sprite.getPosition().x / TAM_BLOCO,
		this->sprite.getPosition().y / TAM_BLOCO
	);
}

// _______________________________________________________________________________
HitBox Personagem::getHitbox() const { return this->hitbox; }

ComponenteMovimento* Personagem::getMovComp() { return &this->compMov; }
