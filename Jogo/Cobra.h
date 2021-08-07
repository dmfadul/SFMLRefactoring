#pragma once
#include "Inimigo.h"
#include "ListaJogadores.h"

#define VIDA_INICIAL_COBRA 80
#define DANO_COBRA 30
#define VEL_MAX_COBRA 1.5
#define MAX_COOLDOWN_PULO 5000 // milisegundos 

class Cobra :
    public Inimigo
{
private:
    ListaJogadores* jogadores;
    sf::Clock timer_pulo;
    int cooldown_pulo;

public:
    Cobra();
    Cobra(ListaJogadores* jogadores, sf::Vector2f position);
    ~Cobra();

    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
};

