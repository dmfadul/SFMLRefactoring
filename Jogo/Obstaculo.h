#pragma once
#include "Entidade.h"
#include "Jogador.h"

class Obstaculo :
    public Entidade
{
protected:
    float dano;

public:
    Obstaculo(const int indice = 0, const bool colidir = false);
    ~Obstaculo();

    void iniciarSprite(int indice);
    virtual void realizarAcao(Jogador* p) = 0;

};
