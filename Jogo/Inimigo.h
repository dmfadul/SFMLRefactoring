#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
protected:
    bool direction;

public:
    Inimigo();
    ~Inimigo();

    bool getDirection();
};

