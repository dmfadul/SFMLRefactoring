#pragma once
#include "Ente.h"
#include "Mapa.h"
#include "CowGirl.h"
#include "GerenciadorColisoes.h"

/* Classe abstrata de Fase */
class Fase :
    public Ente
{
protected:
    Mapa mapa;
    GerenciadorColisoes gerColisoes;
    sf::Text textoScore;
    sf::Font fonte;
    std::vector<Personagem* > personagens;

public:
    // Construtoras e Destrutoras
    Fase(JogoInfo* pji = NULL);
    virtual ~Fase();

    // metodos de inicializacao
    void iniciarPersonagens();
    void iniciarMapa(std::string dir, int ini, int qtd, int tipo = 1);
    void iniciarTextoScore();
    void iniciarGerenciadorColisoes();
};

