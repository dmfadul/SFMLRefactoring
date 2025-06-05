#pragma once
#include "Lista.h"
#include "Entities/Personagem.h"

/* Lista que armazena todas as entidades */
class ListaEntidades
{
private:
	// lista
	Lista<Entidade > listaEntidades;

public:
	// construtoras e destrutoras
	ListaEntidades();
	~ListaEntidades();

	// metodos
	void incluirEntidade(Entidade* j);
	void removerEntidade(int id);
	bool listaVazia();
	Lista<Entidade >::Elemento<Entidade>* getPrimeiro();
};

