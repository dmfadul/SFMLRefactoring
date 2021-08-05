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
	bool excluirProjetil(int id);
	Lista<Projetil >::Elemento<Projetil>* getPrimeiro();

};

