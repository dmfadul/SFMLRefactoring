#pragma once
#include "Fase.h"
#include "Cowboy.h"
#include "CowGirl.h"
#include "Dragao.h"

class NinhoDoDragao :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(JogoInfo* pji = NULL, int n_jogadores = 1);
    ~NinhoDoDragao();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);
    
    void iniciarInimigos();
};

