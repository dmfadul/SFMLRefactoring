#pragma once
#include "States/Fase.h"
#include "Entities/Cowboy.h"
#include "Entities/CowGirl.h"
#include "Entities/Dragao.h"
#include "Entities/Cobra.h"

class NinhoDoDragao :
    public Fase
{
private:
    sf::Clock timerInvocarInimigo;

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(int n_jogadores = 1, bool carregar_jogo = false);
    ~NinhoDoDragao();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);
    void invocarInimigo();

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
    
    void iniciarInimigos();
};

