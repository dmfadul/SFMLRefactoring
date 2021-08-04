#include "stdafx.h"
#include "PersonagemInfo.h"

// _______________________________________________________________________________
PersonagemInfo::PersonagemInfo()
{
    this->dano = 0;
    this->hp = 0;
    this->score = 0;
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
void PersonagemInfo::incrementarScore(const int s) { this->score += s; }

void PersonagemInfo::setHP(const int h) { this->hp = h; }

void PersonagemInfo::setDano(const int d) { this->dano = d; }

const int PersonagemInfo::getHp() { return this->hp; }

const int PersonagemInfo::getDano() { return this->dano; }
