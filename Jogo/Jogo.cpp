#include "stdafx.h"
#include "Jogo.h"

// _______________________________________________________________________________
Jogo::Jogo()
{
    // Inicia Configurações iniciais do jogo
	this->iniciarJanela();
    this->iniciarJogoInfo();
}

// _______________________________________________________________________________
Jogo::~Jogo()
{
    
}

// _______________________________________________________________________________
void Jogo::iniciarJanela()
{
	/* Inicia a janela principal do jogo*/
    this->janela.create(sf::VideoMode(800, 600), "Corre Do Gaucho");

    // define taxa de frame
    this->janela.setFramerateLimit(60);
}

// _______________________________________________________________________________
void Jogo::iniciarJogoInfo()
{
    /* Inicia informações do jogo */
    this->jogoInfo.setTamMapa(25, 19);
    this->jogoInfo.setTamEntidade(32.f);
    this->jogoInfo.setJanela(&this->janela);
    this->jogoInfo.setTocaDisco(&this->tocaDisco);

    // Inicia com o Menu Principal
    this->jogoInfo.pushEnte(static_cast<Ente*>(new MenuPrincipal(&this->jogoInfo)));
}

// _______________________________________________________________________________
void Jogo::atualizar()
{
    /* Limpa o frame anterior e prepara um novo frame*/
    this->janela.clear();

    this->atualizarEventos();
    this->jogoInfo.enteTop()->atualizar();

}

// _______________________________________________________________________________
void Jogo::atualizarEventos()
{
    /* Checa por eventos SFML */
    while (this->janela.pollEvent(this->eventosSFML))
    {
        // Atualiza eventos no ente
        this->jogoInfo.enteTop()->atualizarEventos(this->eventosSFML);

        // checa por fechamento de tela
        if (this->eventosSFML.type == sf::Event::Closed)
            this->janela.close();
    }
}

// _______________________________________________________________________________
void Jogo::desenhar()
{
    /* Desenha o novo frame na janela */
    this->jogoInfo.enteTop()->desenhar(this->janela);

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
