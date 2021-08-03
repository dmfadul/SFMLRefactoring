#include "stdafx.h"
#include "ListaPersonagens.h"

ListaPersonagens::ListaPersonagens()
{
}

ListaPersonagens::~ListaPersonagens()
{
	this->listaJogadores.limpaLista();
	this->listaInimigos.limpaLista();
}

void ListaPersonagens::incluirJogador(Jogador* j)
{
	if (j != NULL)
		this->listaJogadores.incluaInfo(j);
}

void ListaPersonagens::incluirInimigo(Inimigo* i)
{
	if (i != NULL)
		this->listaInimigos.incluaInfo(i);
}
