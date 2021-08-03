#include "stdafx.h"
#include "ListaJogadores.h"

ListaJogadores::ListaJogadores()
	: listaJogadores()
{
}

ListaJogadores::~ListaJogadores()
{
	this->listaJogadores.limpaLista();
}

void ListaJogadores::incluirJogador(Jogador* j)
{
	if (j != NULL)
		this->listaJogadores.incluaInfo(j);
}

Lista<Jogador>::Elemento<Jogador>* ListaJogadores::getPrimeiro()
{
	return this->listaJogadores.getPrimeiro();
}
