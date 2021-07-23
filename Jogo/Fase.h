#pragma once
#include "Ente.h"
#include "Mapa.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:

public:
    // Construtoras e Destrutoras
    Fase(JogoInfo* pji = NULL);
    virtual ~Fase();
};

