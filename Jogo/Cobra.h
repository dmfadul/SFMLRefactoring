#pragma once
#include "Inimigo.h"
#include "ListaJogadores.h"

#define VIDA_INICIAL_COBRA 40
#define DANO_COBRA 30
#define VEL_MAX_COBRA 1.5
#define MAX_COOLDOWN_PULO 5000 // milisegundos 

class Cobra :
    public Inimigo
{
private:
    //variaveis
    ListaJogadores* jogadores;
    sf::Clock timer_pulo;
    int cooldown_pulo;

public:
    // construtoras e destrutoras
    Cobra();
    Cobra(ListaJogadores* jogadores, sf::Vector2f position);
    ~Cobra();

    // metodos
    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();

    int getTipo();
};

