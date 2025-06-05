#pragma once
#include "States/MenuPrincipal.h"
#include "Utils/JogoInfo.h"

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

public:
	// Construtoras e Destrutoras
	Jogo();
	~Jogo();

	// M�todos de Inicializa��o
	void iniciarJanela();

	// M�todos de Atualiza��o
	void atualizar();
	void atualizarEventos();

	// M�todos de Renderiza��o
	void desenhar();

	// Inicia o Jogo
	void executar();
};

