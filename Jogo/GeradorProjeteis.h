#pragma once
#include "ListaInimigos.h"
#include "Projetil.h"
#include "ListaProjeteis.h"
#include "Morcego.h"
class GeradorProjeteis
{
private:
	sf::Clock tempo_atual;
	ListaInimigos* listIni;
	ListaProjeteis* listProj;

public:
	GeradorProjeteis();
	~GeradorProjeteis();

	void CriarProjetil();

	void iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp);
};

