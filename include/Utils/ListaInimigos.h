#pragma once
#include "Lista.h"
#include "Entities/Inimigo.h"
/* Lista que armazena os inimigos */
class ListaInimigos
{
private:
	Lista<Inimigo> listaInimigos;

public:
	// construtoras e destrutoras
	ListaInimigos();
	~ListaInimigos();

	// metodos
	void incluirInimigo(Inimigo* i);
	void removerInimigo(int id);
	const bool listaVazia();
	Lista<Inimigo>::Elemento<Inimigo>* getPrimeiro();
};

