#include "stdafx.h"
#include "Bloco.h"

// _______________________________________________________________________________
Bloco::Bloco(const bool colidir)
{
    this->colidir = colidir;
}

// _______________________________________________________________________________
Bloco::~Bloco()
{
}

// _______________________________________________________________________________
const bool Bloco::getColidir()
{
    return this->colidir;
}

// _______________________________________________________________________________
void Bloco::setPosicao(const float x, const float y)
{
    this->sprite.setPosition(x, y);
}

// _______________________________________________________________________________
void Bloco::atualizar()
{
}

// _______________________________________________________________________________
void Bloco::desenhar(sf::RenderTarget& janela)
{
    janela.draw(this->sprite);
}
