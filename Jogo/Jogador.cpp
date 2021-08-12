#include "stdafx.h"
#include "Jogador.h"

// _______________________________________________________________________________
Jogador::Jogador(){
	this->listaProjeteis = NULL;
	this->listaEntidades = NULL;
}

// _______________________________________________________________________________
Jogador::Jogador(ListaProjeteis* lp, ListaEntidades* le)
{
	this->listaProjeteis = lp;
	this->listaEntidades = le;
}

// _______________________________________________________________________________
Jogador::~Jogador(){}

// _______________________________________________________________________________
void Jogador::atirar()
{
	Shuriken* proj = new Shuriken(this->getHitbox().getCima(), this->getMovComp()->getDirecao());
	 this->listaProjeteis->incluirProjetil(proj);
	 this->listaEntidades->incluirEntidade(proj);
}

// _______________________________________________________________________________
void Jogador::iniciarJogador(ListaProjeteis* lp, ListaEntidades* le)
{
	this->listaProjeteis = lp;
	this->listaEntidades = le;
}

