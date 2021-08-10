#pragma once
#include "Lista.h"
#include "Personagem.h"

class ListaEntidades
{
private:
	Lista<Entidade > listaEntidades;

public:
	ListaEntidades();
	~ListaEntidades();

	void incluirEntidade(Entidade* j);
	void removerEntidade(int id);
	bool listaVazia();
	Lista<Entidade >::Elemento<Entidade>* getPrimeiro();
};

