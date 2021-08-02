#pragma once
#include "Entidade.h"
#include "Personagem.h"

class Obstaculo :
    public Entidade
{
protected:
    float dano;

public:
    Obstaculo(const int indice = 0, const bool colidir = false);
    ~Obstaculo();

    void iniciarSprite(int indice);
    virtual void realizarAcao(Personagem* p) = 0;

};
