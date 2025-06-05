#include "Core/stdafx.h"
#include "Core/GeradorProjeteis.h"

// _______________________________________________________________________________
GeradorProjeteis::GeradorProjeteis():listIni(NULL),listProj(NULL), listEnt(NULL){}

// _______________________________________________________________________________
GeradorProjeteis::~GeradorProjeteis(){
	this->listIni = 0;
	this->listProj = 0;
	this->listEnt = 0;
}

// _______________________________________________________________________________
void GeradorProjeteis::CriarProjetil(Projetil* projetil)
{
	// Cria um novo proj�til em um inimigo

	if (projetil != 0) {
		this->listProj->incluirProjetil(projetil);
		this->listEnt->incluirEntidade(projetil);
	}
}

// _______________________________________________________________________________
void GeradorProjeteis::ExcluirProjetil()
{
	Lista<Projetil>::Elemento<Projetil>* proj = listProj->getPrimeiro();
	Projetil* pproj;

	while (proj != 0)
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