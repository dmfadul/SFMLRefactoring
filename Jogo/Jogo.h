#pragma once

#include "MenuPrincipal.h"

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

	// Armazena todos os entes
	std::stack<Ente* > entes;
	EnteInfo enteInfo;

public:
	// Construtoras e Destrutoras
	Jogo();
	~Jogo();

	// Métodos de Inicialização
	void iniciarJanela();
	void iniciarEnte();

	// Métodos de Atualização
	void atualizar();
	void atualizarEventos();

	// Métodos de Renderização
	void desenhar();

	// Inicia o Jogo
	void executar();
};

