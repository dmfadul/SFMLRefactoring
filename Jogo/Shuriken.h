#pragma once
#include "Projetil.h"
class Shuriken :
    public Projetil
{
public:
    Shuriken();
    Shuriken(sf::Vector2f posicao, bool direcao);
    ~Shuriken();

};

