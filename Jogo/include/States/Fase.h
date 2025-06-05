#pragma once
#include "Entities/Ente.h"
#include "Levels/Mapa.h"
#include "Entities/CowGirl.h"
#include "Core/GerenciadorColisoes.h"
#include "Utils/ListaJogadores.h"
#include "Utils/ListaInimigos.h"
#include "Utils/ListaProjeteis.h"
#include "Utils/ListaEntidades.h"
#include "Core/GeradorProjeteis.h"
#include "Entities/CaixaPause.h"
#include "UI/TelaAdicionarPontuacao.h"
#include "Core/GerenciadorJogoSalvo.h"

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
    GerenciadorJogoSalvo gerJogoSalvo;
    GeradorProjeteis gerProj;

public:
    // Construtoras e Destrutoras
    Fase(int n_jogadores = 1);
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
    void atualizarScore(int incremento);
    void salvarJogo();
    void carregarJogo();
    void desenharEntidades(sf::RenderTarget& janela);
    void realizarAcaoMenuPause();
};

