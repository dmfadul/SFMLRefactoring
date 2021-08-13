#include "stdafx.h"
#include "Inimigo.h"

// _______________________________________________________________________________
Inimigo::Inimigo():direction(true), recompensa(0) {
	this->barraVida.setCor(sf::Color::Red);
	this->barraVida.setTam(40.f, 8.f);
	this->barraVida.setTamTexto(0);
}

// _______________________________________________________________________________
Inimigo::~Inimigo(){}

// _______________________________________________________________________________
const bool Inimigo::getDirection() const{
	return this->direction;
}

// _______________________________________________________________________________
const int Inimigo::getRecompensa() const{
	return this->recompensa;
}
