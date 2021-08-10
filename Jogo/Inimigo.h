#pragma once
#include "Personagem.h"
class Inimigo :
    public Personagem
{
protected:
    // direcao que o inimigo esta andandos
    bool direction;

public:
    // construtoras e destrutoras
    Inimigo();
    ~Inimigo();

    // setters e getters
    const bool getDirection() const;

    virtual int getTipo() = 0;
};

