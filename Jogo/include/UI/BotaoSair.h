#pragma once
#include "BuilderBotao.h"
class BotaoSair :
    public BuilderBotao
{
public:
    // construtoras e destrutoras
    BotaoSair();
    ~BotaoSair();

    // metodos
    gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto);
};

