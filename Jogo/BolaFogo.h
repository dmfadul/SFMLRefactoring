#pragma once
#include "Projetil.h"
class BolaFogo :
    public Projetil
{
public:
    BolaFogo(sf::Vector2f posicao, bool direcao);
    BolaFogo();
    ~BolaFogo();
};

