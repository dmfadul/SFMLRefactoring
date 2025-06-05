#pragma once
#include "Entities/Jogador.h"
class CowGirl :
    public Jogador
{
private:

public:
    // construtoras e destrutoras
    CowGirl();
    CowGirl(ListaProjeteis* lp, ListaEntidades* le);
    ~CowGirl();

    void iniciarCowgirl();
    void desenhar(sf::RenderTarget& janela);
    void mover();
    void atualizar();
};

