#pragma once
#include "Tela.h"
#include "Mapa.h"
#include "CowGirl.h"
#include "GerenciadorColisoes.h"
#include "ListaJogadores.h"
#include "ListaInimigos.h"
#include "ListaProjeteis.h"
#include "GeradorProjeteis.h"
/* Classe abstrata de Fase */
class Fase :
    public Tela
{
protected:
    int nJogadores;
    Mapa mapa;
    GerenciadorColisoes gerColisoes;
    sf::Text textoScore;
    sf::Font fonte;
    ListaJogadores listaJog;
    ListaInimigos listaIni;
    ListaProjeteis listaProj;
    GeradorProjeteis gerProj;

public:
    // Construtoras e Destrutoras
    Fase(JogoInfo* pji = NULL, int n_jogadores = 1);
    virtual ~Fase();

    // metodos de inicializacao
    void iniciarPersonagens();
    void iniciarMapa(std::string dir, int ini, int qtd, int tipo = 1);
    void iniciarTextoScore();
    void iniciarGerenciadorColisoes();
    void iniciarGeradorProjeteis();
    virtual void iniciarInimigos() = 0;
};

