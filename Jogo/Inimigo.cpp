#include "stdafx.h"
#include "Inimigo.h"

// _______________________________________________________________________________
Inimigo::Inimigo():direction(true), recompensa(0) {}

// _______________________________________________________________________________
Inimigo::~Inimigo(){}

// _______________________________________________________________________________
const bool Inimigo::getDirection() const{
	return this->direction;
}

const int Inimigo::getRecompensa() const{
	return this->recompensa;
}
