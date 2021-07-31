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
    void mover(char direcao, float velocidade);
    void atualizar();
    bool verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

};

