#pragma once
#include "Jogador.h"
class Cowboy2 :
    public Jogador
{

private:

public:
    // construtoras e destrutoras
    Cowboy2(std::string imgCaminho = "");
    ~Cowboy2();

    void desenhar(sf::RenderTarget& janela);
    void mover(char direcao, float velocidade);
    void atualizar();
    bool verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

};

