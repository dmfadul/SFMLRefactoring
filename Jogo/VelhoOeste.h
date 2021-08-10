#pragma once
#include "NinhoDoDragao.h"
#include "Jogador.h"
#include "TelaMorte.h"
#include "Bruxa.h"
#include "Cobra.h"

class VelhoOeste :
    public Fase
{
private:
    sf::Clock timerInvocarCobra;
    int qtdMaxCobras;
    int qtdCobras;

public:
    // Construtoras e Destrutoras
    VelhoOeste(JogoInfo* pji = NULL, int n_jogadores = 1);
    ~VelhoOeste();

    // Criar inimigos
    void invocarCobra();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);
    void iniciarInimigos();

};
