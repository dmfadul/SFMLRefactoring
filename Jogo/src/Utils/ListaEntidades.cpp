#include "stdafx.h"
#include "ListaEntidades.h"

// _______________________________________________________________________________
ListaEntidades::ListaEntidades()
{
}

// _______________________________________________________________________________
ListaEntidades::~ListaEntidades()
{
    this->listaEntidades.limpaLista();
}

// _______________________________________________________________________________
void ListaEntidades::incluirEntidade(Entidade* j)
{
    if (j != 0)
        this->listaEntidades.incluaInfo(j);
}

// _______________________________________________________________________________
void ListaEntidades::removerEntidade(int id)
{
    this->listaEntidades.removerElemento(id);
}

// _______________________________________________________________________________
bool ListaEntidades::listaVazia()
{
    return this->listaEntidades.listaVazia();
}

// _______________________________________________________________________________
Lista<Entidade>::Elemento<Entidade>* ListaEntidades::getPrimeiro()
{
    return this->listaEntidades.getPrimeiro();
}

