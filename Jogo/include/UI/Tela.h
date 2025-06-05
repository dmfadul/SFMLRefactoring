#pragma once
#include "Entities/Ente.h"
class Tela :
    public Ente
{
protected:
    sf::Font fonte;

public:
    // construtoras e destrutoras
    Tela();
    ~Tela();

    // metodos de inicializa��o
    void carregarFonte(std::string diretorio);
};

