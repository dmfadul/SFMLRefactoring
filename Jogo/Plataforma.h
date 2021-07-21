#pragma once
#include "Entidade.h"

/* Classe das plataformas do jogo */
class Plataforma :
    public Entidade
{
private:

public:
    // construtoras e destrutoras
    Plataforma(int indice = 0,const bool colidir = true);
    ~Plataforma();


};

