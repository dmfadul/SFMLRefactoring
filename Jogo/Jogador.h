#pragma once
#include "Personagem.h"
#define VEL_MAX_PLAYER 4

class Jogador :
    public Personagem
{
private:

public:
    Jogador();
    ~Jogador();

    void iniciarHitbox();
    void iniciarCompMov();
};
