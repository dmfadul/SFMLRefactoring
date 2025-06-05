#pragma once
#include "Entities/ObstaculoDanoso.h"

#define DANO_CACTO 15

class Cactus :
    public ObstaculoDanoso
{
public:
    // construtoras e destrutoras
    Cactus(const int indice = 0);
    ~Cactus();

    // realiza a��o especifica do cactus
    void realizarAcao(Jogador* p);

};