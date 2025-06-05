#pragma once
#include "States/Menu.h"
#include "Levels/VelhoOeste.h"

class MenuQtdJogadores :
    public Menu
{
private:
    // enumera botoes
    enum BotoesMenu {
        um_jogador,
        dois_jogadores,
        voltar
    };

public:
    // Construtoras e Destrutoras
    MenuQtdJogadores();
    ~MenuQtdJogadores();

    // Metodos de Inicializa��o
    void iniciarBotoes();

    // M�todos de Atualiza��o
    void atualizar();
    void GerenciarCliqueBotao();
};

