#pragma once
#include "Projetil.h"
class Morcego :
    public Projetil
{

public:

    Morcego();
    Morcego(sf::Vector2f posicao, bool direcao);
    ~Morcego();

};

