#pragma once
#include "ListaInimigos.h"
#include "Projetil.h"
#include "ListaProjeteis.h"
#include "ListaEntidades.h"
#include "Morcego.h"
#include "BolaFogo.h"
class GeradorProjeteis
{
private:
	ListaInimigos* listIni;
	ListaProjeteis* listProj;
	ListaEntidades* listEnt;

public:
	GeradorProjeteis();
	~GeradorProjeteis();

	void CriarProjetil(Projetil* projetil);
	void ExcluirProjetil();

	void iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp, ListaEntidades* le);


};

