#pragma once
#include "Bloco.h"
#include "Jogador.h"

class Obstaculo :
    public Bloco
{
protected:
    // variaveis
    float dano;

public:
    // construtoras e destrutoras
    Obstaculo(const int indice = 0, const bool colidir = false);
    ~Obstaculo();

    // metodos 
    void iniciarSprite(int indice, float scale_x, float scale_y);
    virtual void realizarAcao(Jogador* p) = 0;

};
