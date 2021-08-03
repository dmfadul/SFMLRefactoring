#pragma once
#include "Lista.h"
#include "Projetil.h"
class ListaProjeteis
{
private:
	Lista<Projetil> listaProjeteis;

public:
	ListaProjeteis();
	~ListaProjeteis();

	void incluirProjetil(Projetil* p);
	Lista<Projetil >::Elemento<Projetil>* getPrimeiro();

};

