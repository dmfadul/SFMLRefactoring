#pragma once
#include "Ente.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:

public:
    // Construtoras e Destrutoras
    Fase();
    Fase(EnteInfo* ente);
    virtual ~Fase();
};

