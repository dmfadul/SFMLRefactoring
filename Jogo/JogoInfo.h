#pragma once
#include "TocaDisco.h"

class Ente;

/* Classe container para as informacoes do jogo */
class JogoInfo
{
private:
    // Variaveis
    std::stack<Ente* > entes;
    som::TocaDisco* tocaDisco;
    static JogoInfo* _instancia;
    bool encerrar;
    JogoInfo();

public:
    ~JogoInfo();

    static JogoInfo* getInstancia();

    // setters
    void setEncerrar(const bool e);

    // getters
    const bool getEncerrar() const;
    som::TocaDisco* getTocaDisco();
    Ente* enteTop();
    
    // metodos
    void pushEnte(Ente* e);
    void popEnte();
    void trocarEnte(Ente* e);
};

