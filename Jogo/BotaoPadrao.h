#pragma once
#include "BuilderBotao.h"

class BotaoPadrao :
    public BuilderBotao
{
public:
    BotaoPadrao();
    ~BotaoPadrao();

    gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto);
};

