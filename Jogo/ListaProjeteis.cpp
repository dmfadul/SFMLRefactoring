#include "stdafx.h"
#include "ListaProjeteis.h"

ListaProjeteis::ListaProjeteis()
	: listaProjeteis()
{
}

ListaProjeteis::~ListaProjeteis()
{
	this->listaProjeteis.limpaLista();
}

void ListaProjeteis::incluirProjetil(Projetil *p)
{
	if (p != NULL)
		this->listaProjeteis.incluaInfo(p);
}

Lista<Projetil>::Elemento<Projetil>* ListaProjeteis::getPrimeiro()
{
	return this->listaProjeteis.getPrimeiro();
}