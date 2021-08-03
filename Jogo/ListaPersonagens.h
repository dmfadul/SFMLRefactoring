#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
class ListaPersonagens
{
private:
	Lista<Jogador > listaJogadores;
	Lista<Inimigo > listaInimigos;

public:
	ListaPersonagens();
	~ListaPersonagens();

	void incluirJogador(Jogador* j);
	void incluirInimigo(Inimigo* i);

};

