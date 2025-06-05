#pragma once
#include "Personagem.h"
#include "BarraVida.h"
#include "Shuriken.h"
#include "ListaProjeteis.h"
#include "ListaEntidades.h"
#define VEL_MAX_PLAYER 4
#define VIDA_INICIAL_JOGADOR 300
#define DANO_ATAQUE 20

class Jogador :
    public Personagem
{
protected:
    // variaveis
    ListaProjeteis* listaProjeteis;
    ListaEntidades* listaEntidades;
    sf::Clock cooldown_disparo;

public:
    // construtoras e destrutoras
    Jogador();
    Jogador(ListaProjeteis* lp, ListaEntidades* le);
    ~Jogador();

    // metodos
    void atirar();
    void iniciarJogador(ListaProjeteis* lp, ListaEntidades* le);

};
