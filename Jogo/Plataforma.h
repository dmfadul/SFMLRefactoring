#pragma once
#include "Bloco.h"

/* Classe das plataformas do jogo */
class Plataforma :
    public Bloco
{
private:

public:
    // construtoras e destrutoras
    Plataforma(int indice = 0,const bool colidir = true);
    ~Plataforma();

    // metodos
    void iniciarSprite(int indice, float scale_x, float scale_y);
};

