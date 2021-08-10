#pragma once
#include "BuilderBotao.h"
class BotaoSair :
    public BuilderBotao
{
public:
    BotaoSair();
    ~BotaoSair();

    gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto);
};

