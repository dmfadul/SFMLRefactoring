#pragma once
#include "Projetil.h"
class Morcego :
    public Projetil
{

public:

    Morcego();
    Morcego(int indice, sf::Vector2f posicao);
    ~Morcego();

    void iniciarSprite(int indice);

};

