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
	Lista<Inimigo>::Elemento<Inimigo>* getPrimeiro();
};

