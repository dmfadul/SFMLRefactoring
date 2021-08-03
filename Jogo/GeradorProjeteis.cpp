#include "stdafx.h"
#include "GeradorProjeteis.h"

GeradorProjeteis::GeradorProjeteis():listIni(NULL),listProj(NULL){}

GeradorProjeteis::~GeradorProjeteis(){}

void GeradorProjeteis::CriarProjetil()
{
	
	Lista<Inimigo>::Elemento<Inimigo>* ini = listIni->getPrimeiro();
	Inimigo* pini;
	Morcego* pmor;
	while (ini != NULL)
	{
		if (tempo_atual.getElapsedTime().asSeconds() >= 2)
		{
			cout << "teste" << endl;
			pini = ini->getInfo();
			pmor = new Morcego(1, pini->getPosition());
			listProj->incluirProjetil(static_cast<Projetil*>(pmor));
			tempo_atual.restart();
		}
		ini = ini->getProximo();
	}
}

void GeradorProjeteis::iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp)
{
	this->listIni = li;
	this->listProj = lp;
}