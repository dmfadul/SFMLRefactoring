#pragma once
#include "Lista.h"
#include "Inimigo.h"
class ListaInimigos
{
private:
	Lista<Inimigo> listaInimigos;

public:
	ListaInimigos();
	~ListaInimigos();

	void incluirInimigo(Inimigo* i);
	void removerInimigo(int id);
	const bool listaVazia();
	Lista<Inimigo>::Elemento<Inimigo>* getPrimeiro();
};

