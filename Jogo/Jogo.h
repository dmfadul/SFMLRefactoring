#pragma once

#include "MenuPrincipal.h"
#include "JogoInfo.h"
#include "TocaDisco.h"

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

	// Armazena as informaçoes do jogo
	JogoInfo jogoInfo;

	TocaDisco tocaDisco;

public:
	// Construtoras e Destrutoras
	Jogo();
	~Jogo();

	// Métodos de Inicialização
	void iniciarJanela();
	void iniciarJogoInfo();

	// Métodos de Atualização
	void atualizar();
	void atualizarEventos();

	// Métodos de Renderização
	void desenhar();

	// Inicia o Jogo
	void executar();
};

