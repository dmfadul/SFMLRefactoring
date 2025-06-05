#pragma once
#include "Entities/ObstaculoDanoso.h"

#define DANO_ESPINHO 10

class Espinho :
    public ObstaculoDanoso
{
private:

public:
    Espinho(const int indice = 0);
    ~Espinho();

    void realizarAcao(Jogador* p);
};

