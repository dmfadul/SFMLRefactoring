#pragma once

class Ente;

/* Classe container para as informações do jogo */
class JogoInfo
{
private:
    // Variaveis
    float tamEntidade;
    bool encerrarEnte;
    sf::RenderWindow* janela;
    std::stack<Ente* >* entes;

public:
    JogoInfo();
    ~JogoInfo();

    // setters
    void setTamEntidade(const float te);
    void setEncerrarEnte(const bool ee);
    void setJanela(sf::RenderWindow* j);
    void setEntes(std::stack<Ente* >* e);

    // getters
    const float getTamEntidade() const;
    const bool getEncerrarEnte() const;
    const sf::RenderWindow* getJanela() const;
    const std::stack<Ente* >* getEntes() const;
    
    // metodos
    void pushEnte(Ente* e);
    void fecharJanela();
};

