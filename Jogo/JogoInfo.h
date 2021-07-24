#pragma once
#include "TocaDisco.h"

class Ente;

/* Classe container para as informa��es do jogo */
class JogoInfo
{
private:
    // Variaveis
    float tamEntidade;
    TocaDisco* tocaDisco;
    sf::Vector2u tamMapa;
    sf::RenderWindow* janela;
    std::stack<Ente* > entes;

public:
    JogoInfo();
    ~JogoInfo();

    // setters
    void setTamEntidade(const float te);
    void setJanela(sf::RenderWindow* j);
    void setTocaDisco(TocaDisco* td);
    void setTamMapa(unsigned x, unsigned y);

    // getters
    const sf::Vector2u getTamMapa() const;
    const sf::Vector2u getTamJanela() const;
    const float getTamEntidade() const;
    TocaDisco* getTocaDisco() const;
    Ente* enteTop();
    
    // metodos
    void pushEnte(Ente* e);
    void popEnte();
    void trocarEnte(Ente* e);
    void fecharJanela();
};

