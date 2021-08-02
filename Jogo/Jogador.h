#pragma once
#include "Personagem.h"
#include "Barra.h"
#define VEL_MAX_PLAYER 4
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20

class Jogador :
    public Personagem
{
private:

public:
    Jogador();
    ~Jogador();

};
