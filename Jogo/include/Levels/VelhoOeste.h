#pragma once
#include "Levels/NinhoDoDragao.h"
#include "Entities/Jogador.h"
#include "UI/TelaAdicionarPontuacao.h"
#include "Entities/Bruxa.h"
#include "Entities/Cobra.h"

class VelhoOeste :
    public Fase
{
private:
    sf::Clock timerInvocarCobra;
    int qtdMaxCobras;
    int qtdCobras;

public:
    // Construtoras e Destrutoras
    VelhoOeste(int n_jogadores = 1, bool carregar_jogo = false);
    ~VelhoOeste();

    // Criar inimigos
    void invocarCobra();

    // M�todos de Atualiza��o
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
    void iniciarInimigos();

};
