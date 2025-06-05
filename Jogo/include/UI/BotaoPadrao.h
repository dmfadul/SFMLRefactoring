#pragma once
#include "BuilderBotao.h"

class BotaoPadrao :
    public BuilderBotao
{
public:
    // construtoras e destrutoras
    BotaoPadrao();
    ~BotaoPadrao();

    // metodos
    gui::Botao* criarBotao(float pos_x, float pos_y, std::string texto);
};

