#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{

private:
    sf::Texture texture;
    sf::Sprite sprite;

public:

    Cowboy();
    Cowboy(std::string imgDirectory);
    ~Cowboy();

    void draw(sf::RenderTarget& janela);
    void move(char direction, float speed);
    void atualizar();
};

