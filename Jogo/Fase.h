#pragma once
#include "Ente.h"
#include "Mapa.h"
#include "CowGirl.h"
#include "GerenciadorColisoes.h"
#include "ListaJogadores.h"
#include "ListaInimigos.h"
#include "ListaProjeteis.h"
#include "ListaEntidades.h"
#include "GeradorProjeteis.h"
#include "CaixaPause.h"
#include "TelaMorte.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:
    int nJogadores;
    bool pausado;
    Mapa mapa;
    GerenciadorColisoes gerColisoes;
    CaixaPause caixaPause;
    Gui textoScore;
    ListaJogadores listaJog;
    ListaInimigos listaIni;
    ListaProjeteis listaProj;
    ListaEntidades listaEntidades;
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

    // metodos
    void atualizarEntidades();
    void desenharEntidades(sf::RenderTarget& janela);
    void realizarAcaoMenuPause();
};

