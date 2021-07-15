#include "stdafx.h"
#include "Jogo.h"

// _______________________________________________________________________________
Jogo::Jogo()
{
    // Inicia Variaveis
	this->iniciarJanela();
    this->iniciarEnte();
}

// _______________________________________________________________________________
Jogo::~Jogo()
{
}

// _______________________________________________________________________________
void Jogo::iniciarJanela()
{
	/* Inicia a janela principal do jogo*/
    this->janela.create(sf::VideoMode(800, 600), "NOME DO JOGO (ALTERAR)");

    // define taxa de frame
    this->janela.setFramerateLimit(60);
}

// _______________________________________________________________________________
void Jogo::iniciarEnte()
{
    /* Inicia os dados dos entes */
    this->enteInfo.tamEntidade = 32.f;
    this->enteInfo.janela = &this->janela;
    this->enteInfo.entes = &this->entes;

    // Inicia com o Menu Principal
    this->entes.push(new MenuPrincipal(&this->enteInfo));
}

// _______________________________________________________________________________
void Jogo::atualizar()
{
    /* Limpa o frame anterior e prepara um novo frame*/
    this->janela.clear();

    // desaloca o ente caso ele foi encerrado
    if (this->entes.top()->getEncerrar()) {
        delete this->entes.top();
        this->entes.pop();
        this->entes.top()->setEncerrar(false);
    }

    this->entes.top()->atualizar();
	this->atualizarEventos();

}

// _______________________________________________________________________________
void Jogo::atualizarEventos()
{
    /* Checa por eventos SFML */
    while (this->janela.pollEvent(this->eventosSFML))
    {
        // Atualiza eventos no ente
        this->entes.top()->atualizarEventos(this->eventosSFML);

        // checa por fechamento de tela
        if (this->eventosSFML.type == sf::Event::Closed)
            this->janela.close();
    }
}

// _______________________________________________________________________________
void Jogo::desenhar()
{
    /* Desenha o novo frame na janela */
    this->entes.top()->desenhar(this->janela);

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
