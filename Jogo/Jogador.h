#pragma once
#include "Personagem.h"
class Jogador :
    public Personagem
{

private:
    sf::Texture pTexture;
    sf::Sprite pSprite;

public:
    Jogador();

    ~Jogador();


};

