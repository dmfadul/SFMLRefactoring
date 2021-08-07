#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{

private:

public:
    Cowboy();
    ~Cowboy();

    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
};

