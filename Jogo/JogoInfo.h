#pragma once
#include "TocaDisco.h"

class Tela;

/* Classe container para as informa��es do jogo */
class JogoInfo
{
private:
    // Variaveis
    sf::View* view;
    std::stack<Tela* > telas;
    TocaDisco* tocaDisco;
    bool encerrar;

public:
    JogoInfo();
    ~JogoInfo();

    // setters
    void setEncerrar(const bool e);

    // getters
    const bool getEncerrar() const;
    TocaDisco* getTocaDisco() const;
    Tela* telaTop();
    
    // metodos
    void pushTela(Tela* e);
    void popTela();
    void trocarTela(Tela* e);
};

