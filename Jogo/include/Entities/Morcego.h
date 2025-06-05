#pragma once
#include "Entities/Projetil.h"
class Morcego :
    public Projetil
{

public:
    // construtoras e destrutoras
    Morcego();
    Morcego(sf::Vector2f posicao, bool direcao);
    ~Morcego();

};

