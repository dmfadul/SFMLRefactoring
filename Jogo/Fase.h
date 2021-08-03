#pragma once
#include "Ente.h"
#include "Mapa.h"
#include "CowGirl.h"
#include "GerenciadorColisoes.h"
#include "ListaJogadores.h"
#include "ListaInimigos.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:
    int nJogadores;
    Mapa mapa;
    GerenciadorColisoes gerColisoes;
    sf::Text textoScore;
    sf::Font fonte;
    ListaJogadores listaJog;
    ListaInimigos listaIni;

public:
    // Construtoras e Destrutoras
    Fase(JogoInfo* pji = NULL, int n_jogadores = 1);
    virtual ~Fase();

    // metodos de inicializacao
    void iniciarPersonagens();
    void iniciarMapa(std::string dir, int ini, int qtd, int tipo = 1);
    void iniciarTextoScore();
    void iniciarGerenciadorColisoes();
    virtual void iniciarInimigos() = 0;
};

