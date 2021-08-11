#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
protected:
    // direcao que o inimigo esta andandos
    bool direction;
    int recompensa;

public:
    // construtoras e destrutoras
    Inimigo();
    ~Inimigo();

    // setters e getters
    const bool getDirection() const;
    const int getRecompensa() const;

    virtual int getTipo() = 0;
};

