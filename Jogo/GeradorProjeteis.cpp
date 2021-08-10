#include "stdafx.h"
#include "GeradorProjeteis.h"

// _______________________________________________________________________________
GeradorProjeteis::GeradorProjeteis():listIni(NULL),listProj(NULL),ini(NULL), listEnt(NULL){}

// _______________________________________________________________________________
GeradorProjeteis::~GeradorProjeteis(){
	this->ini = NULL;
	this->listIni = NULL;
	this->listProj = NULL;
	this->listEnt = NULL;
}

// _______________________________________________________________________________
void GeradorProjeteis::CriarProjetil()
{
	// Cria um novo projétil em um inimigo
	if (this->ini == NULL)
		this->ini = this->listIni->getPrimeiro();
	else {
		Inimigo* pini;
		Morcego* pmor;
		pini = ini->getInfo();
		if (this->tempo_atual.getElapsedTime().asMilliseconds() > 500)
		{

			pmor = new Morcego(1, pini->getHitbox().getCima(), pini->getDirection());
			this->listProj->incluirProjetil(static_cast<Projetil*>(pmor));
			this->listEnt->incluirEntidade(static_cast<Entidade*>(pmor));
			this->tempo_atual.restart();
			this->ini = ini->getProximo();
		}
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