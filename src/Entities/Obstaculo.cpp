#include "Core/stdafx.h"
#include "Entities/Obstaculo.h"

// _______________________________________________________________________________
Obstaculo::Obstaculo(const bool colidir)
{
    this->colidir = colidir;
}

// _______________________________________________________________________________
Obstaculo::~Obstaculo()
{
}

// _______________________________________________________________________________
const bool Obstaculo::getColidir()
{
    return this->colidir;
}

// _______________________________________________________________________________
void Obstaculo::setPosicao(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

// _______________________________________________________________________________
void Obstaculo::atualizar()
{
}

// _______________________________________________________________________________
void Obstaculo::desenhar(sf::RenderTarget& janela)
{
    janela.draw(this->sprite);
}
