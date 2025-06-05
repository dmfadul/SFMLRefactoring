#pragma once
#include "Entities/Projetil.h"
class Shuriken :
    public Projetil
{
public:
    // construtoras e destrutoras
    Shuriken();
    Shuriken(sf::Vector2f posicao, bool direcao);
    ~Shuriken();

};

