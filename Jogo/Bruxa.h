#pragma once
#include "Inimigo.h"
#define VEL_MAX_PLAYER 2
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20
class Bruxa :
    public Inimigo
{
private:
    int tempo_vida;
    bool direction;

public:
    Bruxa(std::string imgCaminho = "");
    ~Bruxa();

    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();

	
};

