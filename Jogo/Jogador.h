#pragma once
#include "Personagem.h"
#include "BarraVida.h"
#define VEL_MAX_PLAYER 4
#define VIDA_INICIAL_JOGADOR 25000
#define DANO_ATAQUE 20

class Jogador :
    public Personagem
{
private:

public:
    Jogador();
    ~Jogador();

};
