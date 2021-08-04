#pragma once
#include "Obstaculo.h"

#define VELOCIDADE_MAX 0.5

class AreiaDasAlmas :
    public Obstaculo
{
private:

public:
    AreiaDasAlmas(const int indice = 0);
    ~AreiaDasAlmas();

    void realizarAcao(Jogador* p);
};

