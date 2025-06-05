#pragma once
#include "Utils/ListaInimigos.h"
#include "Entities/Projetil.h"
#include "Utils/ListaProjeteis.h"
#include "Utils/ListaEntidades.h"
#include "Entities/Morcego.h"
#include "Entities/BolaFogo.h"
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

