#include "stdafx.h"
#include "Jogo.h"

// _______________________________________________________________________________
Jogo::Jogo()
{
    // Inicia Variaveis
	this->iniciarJanela();

    // REMOVER
    this->test.setFillColor(sf::Color::Red);
    this->test.setSize(sf::Vector2f(100.f, 100.f));
}

// _______________________________________________________________________________
Jogo::~Jogo()
{
}

// _______________________________________________________________________________
void Jogo::iniciarJanela()
{
	/* Inicia a janela principal do jogo*/

    // inicia a janela
	sf::VideoMode dimensoes_janela;
	dimensoes_janela.width = 800;
	dimensoes_janela.height = 600;
    this->janela.create(dimensoes_janela, "NOME DO JOGO (ALTERAR)");

    // define taxa de frame
    this->janela.setFramerateLimit(60);
}

// _______________________________________________________________________________
void Jogo::atualizar()
{
    /* Limpa o frame anterior e prepara um novo frame*/
    this->janela.clear();
	this->atualizarEventos();

    // REMOVER
    this->test.move(1.f, 1.f);
}

// _______________________________________________________________________________
void Jogo::atualizarEventos()
{
    /* Checa por eventos SFML */
    while (this->janela.pollEvent(this->eventosSFML))
    {
        if (this->eventosSFML.type == sf::Event::Closed)
            this->janela.close();
    }
}

// _______________________________________________________________________________
void Jogo::desenhar()
{
    /* Desenha o novo frame na janela */

    // REMOVER
    this->janela.draw(this->test);

    this->janela.display();

 
}

// _______________________________________________________________________________
void Jogo::executar()
{
    /* Inicia o jogo e o mantém rodando */
    while (this->janela.isOpen())
    {
        this->atualizar();
        this->desenhar();
    }
}
