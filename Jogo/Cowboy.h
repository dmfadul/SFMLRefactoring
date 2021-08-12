#pragma once
#include "Jogador.h"
class Cowboy :
    public Jogador
{

private:

public:
    Cowboy();
    Cowboy(ListaProjeteis* lp, ListaEntidades* le);
    ~Cowboy();

    void mover();
    void iniciarCowboy();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
};

