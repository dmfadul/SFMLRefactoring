#pragma once
#include "Obstaculo.h"

#define DANO_CACTO 15

class Cactus :
    public Obstaculo
{
private:


public:
    Cactus(const int indice = 0);
    ~Cactus();

    void realizarAcao(Personagem* p);

};