#pragma once
#include "Obstaculo.h"

#define DANO_CACTO 15

class Cactus :
    public Obstaculo
{
public:
    // construtoras e destrutoras
    Cactus(const int indice = 0);
    ~Cactus();

    // realiza ação especifica do cactus
    void realizarAcao(Jogador* p);

};