#include "stdafx.h"
#include "configuracoes.h"
#include "Jogo.h"

// _______________________________________________________________________________
Jogo::Jogo()
    : jogoInfo()
{
    // Inicia Configurações iniciais do jogo
	this->iniciarJanela();

    // Inicia o jogo com o Menu Principal
    this->jogoInfo.pushEnte(static_cast<Ente*>(new MenuPrincipal(&this->jogoInfo)));
}

// _______________________________________________________________________________
Jogo::~Jogo()
{
    
}

// _______________________________________________________________________________
void Jogo::iniciarJanela()
{
	/* Inicia a janela principal do jogo*/
    this->janela.create(sf::VideoMode(TAM_JANELA_X, TAM_JANELA_Y), "Corre Do Gaucho");

    // define taxa de frame
    this->janela.setFramerateLimit(FRAME_RATE);
}

// _______________________________________________________________________________
void Jogo::atualizar()
{
    /* Limpa o frame anterior e prepara um novo frame*/
    this->janela.clear();
    if (this->jogoInfo.getEncerrar())
        this->janela.close();

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
