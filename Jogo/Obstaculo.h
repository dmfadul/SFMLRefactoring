#pragma once
#include "Bloco.h"
#include "Jogador.h"

class Obstaculo :
    public Bloco
{
protected:
    float dano;

public:
    Obstaculo(const int indice = 0, const bool colidir = false);
    ~Obstaculo();

    void iniciarSprite(int indice, float scale_x, float scale_y);
    virtual void realizarAcao(Jogador* p) = 0;

};
