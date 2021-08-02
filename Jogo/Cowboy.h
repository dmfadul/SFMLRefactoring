#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{

private:

public:
    Cowboy(std::string imgCaminho = "");
    ~Cowboy();

    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
};

