#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{

private:

public:
    Cowboy(std::string imgCaminho = "");
    ~Cowboy();

    void desenhar(sf::RenderTarget& janela);
    void mover(char direcao, float velocidade);
    void atualizar();
    bool verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push);
};

