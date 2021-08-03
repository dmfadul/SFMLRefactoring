#pragma once
#include "Entidade.h"
class Projetil :
    public Entidade
{
protected:

    sf::Texture texture;
    sf::Sprite sprite;

public:
    Projetil();
    ~Projetil();
};

