#pragma once
#include "Levels/VelhoOeste.h"
#include "UI/TelaPontuacao.h"
#include "States/MenuEscolhaFases.h"
#include "States/MenuQtdJogadores.h"
#include "UI/BotaoPadrao.h"

/* Classe do Menu Principal */
class MenuPrincipal :
    public Menu
{
private:
    // enumera botoes
    enum BotoesMenu {
        novo_jogo = 0,
        carregar_jogo,
        escolha_de_fases,
        lista_de_pontuacoes,
        sair
    };

public:
    // Construtoras e Destrutoras
    MenuPrincipal();
    ~MenuPrincipal();
    
    // Metodos de Inicializa��o
    void iniciarBotoes();

    // M�todos de Atualiza��o
    void atualizar();
    void carregarJogo();
    void GerenciarCliqueBotao();
};

