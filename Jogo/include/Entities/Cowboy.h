#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{
private:
public:
    // construtoras e destrutoras
    Cowboy();
    Cowboy(ListaProjeteis* lp, ListaEntidades* le);
    ~Cowboy();

    // metodos
    void mover();
    void iniciarCowboy();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
};

