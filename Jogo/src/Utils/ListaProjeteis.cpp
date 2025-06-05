#include "Core/stdafx.h"
#include "Utils/ListaProjeteis.h"

// _______________________________________________________________________________
ListaProjeteis::ListaProjeteis()
	: listaProjeteis()
{
}

// _______________________________________________________________________________
ListaProjeteis::~ListaProjeteis()
{
	this->listaProjeteis.limpaLista();
}

// _______________________________________________________________________________
void ListaProjeteis::incluirProjetil(Projetil *p)
{
	if (p != 0) {
		this->listaProjeteis.incluaInfo(p);
	}
}

// _______________________________________________________________________________
Lista<Projetil>::Elemento<Projetil>* ListaProjeteis::getPrimeiro()
{
	return this->listaProjeteis.getPrimeiro();
}

// _______________________________________________________________________________
bool ListaProjeteis::excluirProjetil(int id)
{
	return this->listaProjeteis.removerElemento(id);
}