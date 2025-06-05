#pragma once
#include "Entities/Ente.h"
#include "Core/GerenciadorBotoes.h"

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

    // M�todos de Atualiza��o
    virtual void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    virtual void desenhar(sf::RenderTarget& janela);
};

