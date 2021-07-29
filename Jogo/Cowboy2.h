#pragma once
#include "Jogador.h"
class Cowboy2 :
    public Jogador
{

private:


public:
    Cowboy2();
    ~Cowboy2();

    Cowboy2(std::string imgCaminho);

    void desenhar(sf::RenderTarget& janela);
    void mover(char direcao, float velocidade);
    void atualizar();
    bool verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

};

