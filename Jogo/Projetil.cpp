#include "stdafx.h"
#include "Projetil.h"


Projetil::Projetil(){}

Projetil::~Projetil(){}

void Projetil::setPosicao(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Projetil::desenharProjetil(sf::RenderTarget& janela)
{
	janela.draw(this->sprite);
}
