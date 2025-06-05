#pragma once
#include "Entities/ObstaculoDanoso.h"

#define VELOCIDADE_MAX 0.5

class AreiaDasAlmas :
    public ObstaculoDanoso
{
private:
    bool size;
public:
    // construtoras e destrutoras
    AreiaDasAlmas(const int indice = 0);
    ~AreiaDasAlmas();

    // metodo da a��o especifica da areia das almas
    void realizarAcao(Jogador* p);
};

