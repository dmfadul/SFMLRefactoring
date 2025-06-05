#pragma once
#include "Menu.h"
#include "VelhoOeste.h"

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

    // Metodos de Inicialização
    void iniciarBotoes();

    // Métodos de Atualização
    void atualizar();
    void GerenciarCliqueBotao();
};

