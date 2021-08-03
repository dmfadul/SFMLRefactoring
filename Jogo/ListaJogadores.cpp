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

void ListaJogadores::removerJogador(int id)
{
	this->listaJogadores.removerElemento(id);
}

bool ListaJogadores::listaVazia()
{
	return this->listaJogadores.listaVazia();
}

Lista<Jogador>::Elemento<Jogador>* ListaJogadores::getPrimeiro()
{
	return this->listaJogadores.getPrimeiro();
}
