#include "stdafx.h"
#include "Personagem.h"

// _______________________________________________________________________________
Personagem::Personagem():
hp(100),
dano(100),
hitbox(){}

// _______________________________________________________________________________
Personagem::~Personagem(){}

// _______________________________________________________________________________
void Personagem::setHP(int h) { this->hp = h; }

void Personagem::setDano(int d) { this->dano = d; }

// _______________________________________________________________________________
const int Personagem::getHP() const { return this->hp; }

const int Personagem::getDano() const { return this->dano; }
