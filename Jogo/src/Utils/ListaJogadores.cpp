#include "stdafx.h"
#include "ListaJogadores.h"

// _______________________________________________________________________________
ListaJogadores::ListaJogadores()
	: listaJogadores()
{
}

// _______________________________________________________________________________
ListaJogadores::~ListaJogadores()
{
	this->listaJogadores.limpaLista();
}

// _______________________________________________________________________________
void ListaJogadores::incluirJogador(Jogador* j)
{
	if (j != 0) 
		this->listaJogadores.incluaInfo(j);

}

// _______________________________________________________________________________
void ListaJogadores::removerJogador(int id)
{
	this->listaJogadores.removerElemento(id);
}

// _______________________________________________________________________________
bool ListaJogadores::listaVazia()
{
	return this->listaJogadores.listaVazia();
}

// _______________________________________________________________________________
Lista<Jogador>::Elemento<Jogador>* ListaJogadores::getPrimeiro()
{
	return this->listaJogadores.getPrimeiro();
}
