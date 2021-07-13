#pragma once

/* Classe Principal */
class Jogo
{
private:
	// Variaveis SFML
	sf::RenderWindow janela;
	sf::Event eventosSFML;

	// REMOVER
	sf::RectangleShape test;

public:
	// Construtoras e Destrutoras
	Jogo();
	~Jogo();

	// Métodos de Inicialização
	void iniciarJanela();

	// Métodos de Atualização
	void atualizar();
	void atualizarEventos();

	// Métodos de Renderização
	void desenhar();

	// Inicia o Jogo
	void executar();
};

