#pragma once
#include "Obstaculo.h"

#define DANO_ESPINHO 10

class Espinho :
    public Obstaculo
{
private:


public:
    Espinho(const int indice = 0);
    ~Espinho();

    void realizarAcao(Personagem* p);
};

