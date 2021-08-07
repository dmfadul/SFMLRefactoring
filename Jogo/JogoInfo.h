#pragma once
#include "TocaDisco.h"

class Ente;

/* Classe container para as informa��es do jogo */
class JogoInfo
{
private:
    // Variaveis
    std::stack<Ente* > entes;
    TocaDisco* tocaDisco;
    bool encerrar;

public:
    JogoInfo();
    ~JogoInfo();

    // setters
    void setEncerrar(const bool e);

    // getters
    const bool getEncerrar() const;
    TocaDisco* getTocaDisco();
    Ente* enteTop();
    
    // metodos
    void pushEnte(Ente* e);
    void popEnte();
    void trocarEnte(Ente* e);
};

