#include "Core/stdafx.h"
#include "configuracoes.h"
#include "Core/Jogo.h"

// _______________________________________________________________________________
Jogo::Jogo()
{
    // Inicia Configura��es iniciais do jogo
	this->iniciarJanela();
    srand((unsigned int)(time(NULL)));

    // Inicia o jogo com o Menu Principal
    JogoInfo::getInstancia()->pushEnte(static_cast<Ente*>(new MenuPrincipal()));
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
    if (JogoInfo::getInstancia()->getEncerrar())
        this->janela.close();

    this->atualizarEventos();
    JogoInfo::getInstancia()->enteTop()->atualizar();

}

// _______________________________________________________________________________
void Jogo::atualizarEventos()
{
    /* Checa por eventos SFML */
    while (this->janela.pollEvent(this->eventosSFML))
    {
        // Atualiza eventos no ente
        JogoInfo::getInstancia()->enteTop()->atualizarEventos(this->eventosSFML);

        // checa por fechamento de tela
        if (this->eventosSFML.type == sf::Event::Closed)
            this->janela.close();
    }
}

// _______________________________________________________________________________
void Jogo::desenhar()
{
    /* Desenha o novo frame na janela */
    JogoInfo::getInstancia()->enteTop()->desenhar(this->janela);

    this->janela.display();
}

// _______________________________________________________________________________
void Jogo::executar()
{
    /* Inicia o jogo e o mant�m rodando */
    while (this->janela.isOpen())
    {
        this->atualizar();
        this->desenhar();
    }
}
