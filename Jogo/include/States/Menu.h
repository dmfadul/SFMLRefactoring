#pragma once
#include "Ente.h"
#include "GerenciadorBotoes.h"

/* Classe Abstrata de um Menu Generico */
class Menu :
    public Ente, public GerenciadorBotoes
{
protected:
    // armazena os botoes do menu 
    sf::RectangleShape caixaBotoes;

public:
    // Construtoras e Destrutoras
    Menu();
    virtual ~Menu();

    // Métodos de Atualização
    virtual void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    virtual void desenhar(sf::RenderTarget& janela);
};

