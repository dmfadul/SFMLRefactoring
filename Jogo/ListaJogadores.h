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
	Lista<Jogador >::Elemento<Jogador>* getPrimeiro();
};

