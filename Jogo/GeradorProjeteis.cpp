#include "stdafx.h"
#include "GeradorProjeteis.h"

// _______________________________________________________________________________
GeradorProjeteis::GeradorProjeteis():listIni(NULL),listProj(NULL), listEnt(NULL){}

// _______________________________________________________________________________
GeradorProjeteis::~GeradorProjeteis(){
	this->listIni = NULL;
	this->listProj = NULL;
	this->listEnt = NULL;
}

// _______________________________________________________________________________
void GeradorProjeteis::CriarProjetil(Projetil* projetil)
{
	// Cria um novo projétil em um inimigo

	if (projetil != NULL) {
		this->listProj->incluirProjetil(projetil);
		this->listEnt->incluirEntidade(projetil);
	}
}

// _______________________________________________________________________________
void GeradorProjeteis::ExcluirProjetil()
{
	Lista<Projetil>::Elemento<Projetil>* proj = listProj->getPrimeiro();
	Projetil* pproj;

	while (proj != NULL)
	{
		pproj = proj->getInfo();
		proj = proj->getProximo();
		if (pproj->getTempoVida() > 2000)
		{
			this->listProj->excluirProjetil(pproj->getId());
			this->listEnt->removerEntidade(pproj->getId());
		}
	}
}

// _______________________________________________________________________________
void GeradorProjeteis::iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp, ListaEntidades* le)
{
	this->listIni = li;
	this->listProj = lp;
	this->listEnt = le;
}