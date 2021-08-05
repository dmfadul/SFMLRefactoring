#include "stdafx.h"
#include "Inimigo.h"

Inimigo::Inimigo():direction(true) {}

Inimigo::~Inimigo(){}

bool Inimigo::getDirection()
{
	return this->direction;
}