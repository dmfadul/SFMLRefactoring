#pragma once
#include "Ente.h"

/* Classe do menu de Pontuação */
class Pontuacao :
    public Ente
{
private:

public:
    // Construtoras e Destrutoras
    Pontuacao();
    Pontuacao(EnteInfo* pei);
    ~Pontuacao();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderWindow& janela);
};

