#pragma once
#include "Lista.h"
#include "Jogador.h"
/* Classe que armazena os jogadores */
class ListaJogadores
{
private:
	Lista<Jogador > listaJogadores;

public:
	// cosntrutoras e destrutoras
	ListaJogadores();
	~ListaJogadores();

	// metodos
	void incluirJogador(Jogador* j);
	void removerJogador(int id);
	bool listaVazia();
	Lista<Jogador >::Elemento<Jogador>* getPrimeiro();
};

