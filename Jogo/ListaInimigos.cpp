#include "stdafx.h"
#include "ListaInimigos.h"

// _______________________________________________________________________________
ListaInimigos::ListaInimigos()
    : listaInimigos()
{
}

// _______________________________________________________________________________
ListaInimigos::~ListaInimigos()
{
    this->listaInimigos.limpaLista();
}

// _______________________________________________________________________________
void ListaInimigos::incluirInimigo(Inimigo* i)
{
    if (i != 0)
        this->listaInimigos.incluaInfo(i);
}

// _______________________________________________________________________________
void ListaInimigos::removerInimigo(int id)
{
    this->listaInimigos.removerElemento(id);
}

// _______________________________________________________________________________
const bool ListaInimigos::listaVazia()
{
    return this->listaInimigos.listaVazia();
}

// _______________________________________________________________________________
Lista<Inimigo>::Elemento<Inimigo>* ListaInimigos::getPrimeiro()
{
    return this->listaInimigos.getPrimeiro();
}