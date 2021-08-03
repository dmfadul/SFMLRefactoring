#pragma once
#include "Lista.h"
#include "Jogador.h"

class ListaJogadores
{
private:
	Lista<Jogador > listaJogadores;

public:
	ListaJogadores();
	~ListaJogadores();

	void incluirJogador(Jogador* j);
	void removerJogador(int id);
	bool listaVazia();
	Lista<Jogador >::Elemento<Jogador>* getPrimeiro();
};

