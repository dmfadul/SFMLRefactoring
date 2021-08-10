#include "stdafx.h"
#include "Inimigo.h"

// _______________________________________________________________________________
Inimigo::Inimigo():direction(true) {}

// _______________________________________________________________________________
Inimigo::~Inimigo(){}

// _______________________________________________________________________________
const bool Inimigo::getDirection() const{
	return this->direction;
}