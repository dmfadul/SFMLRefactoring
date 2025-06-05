#include "stdafx.h"
#include "PersonagemInfo.h"

// variaveis e metodos estaticos
int PersonagemInfo::score = 0;

void PersonagemInfo::setScore(const int s) {
    PersonagemInfo::score = s;
}

const int PersonagemInfo::getScore() {
    return PersonagemInfo::score;
}

// _______________________________________________________________________________
PersonagemInfo::PersonagemInfo()
{
    this->dano = 0;
    this->hp = 0;
}

// _______________________________________________________________________________
PersonagemInfo::~PersonagemInfo()
{
}

// _______________________________________________________________________________
void PersonagemInfo::iniciarPersInfo(int hp, int dano)
{
    this->hp = hp;
    this->dano = dano;
}

// _______________________________________________________________________________
void PersonagemInfo::setHP(const int h) { this->hp = h; }

void PersonagemInfo::setDano(const int d) { this->dano = d; }

const int PersonagemInfo::getHp() { return this->hp; }

const int PersonagemInfo::getDano() { return this->dano; }
