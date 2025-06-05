#pragma once
#include "Entities/Obstaculo.h"
#include "Entities/Jogador.h"

class ObstaculoDanoso :
    public Obstaculo
{
protected:
    // variaveis
    float dano;

public:
    // construtoras e destrutoras
    ObstaculoDanoso(const int indice = 0, const bool colidir = false);
    ~ObstaculoDanoso();

    // metodos 
    void iniciarSprite(int indice, float scale_x, float scale_y);
    virtual void realizarAcao(Jogador* p) = 0;

};
