#pragma once
#include "Inimigo.h"
#define VEL_MAX_BRUXA 1.5
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20
class Bruxa :
    public Inimigo
{
private:
    sf::Clock tempo_vida;
    int tempo_direcao;  

public:
    Bruxa();
    Bruxa(sf::Vector2f position, int tempo_direcao = 50);
    ~Bruxa();

    bool getDirection();

    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();

	
};

