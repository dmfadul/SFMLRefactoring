#pragma once
#include "Lista.h"
#include "Entities/Projetil.h"

/* Lista que armazena projeteis */
class ListaProjeteis
{
private:
	Lista<Projetil> listaProjeteis;

public:
	// construtoras e destrutoras
	ListaProjeteis();
	~ListaProjeteis();

	// metodos
	void incluirProjetil(Projetil* p);
	bool excluirProjetil(int id);
	Lista<Projetil >::Elemento<Projetil>* getPrimeiro();

};

