#pragma once
#include "Ente.h"
class Tela :
    public Ente
{
protected:
    sf::Font fonte;

public:
    // construtoras e destrutoras
    Tela(JogoInfo* pji = NULL);
    ~Tela();

    // metodos de inicialização
    void carregarFonte(std::string diretorio);
};

