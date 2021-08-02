#pragma once
#include "Jogador.h"
class CowGirl :
    public Jogador
{
private:

public:
    // construtoras e destrutoras
    CowGirl(std::string imgCaminho = "");
    ~CowGirl();

    void desenhar(sf::RenderTarget& janela);
    void mover();
    void atualizar();
};

