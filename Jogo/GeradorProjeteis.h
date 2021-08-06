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
	Lista<Inimigo>::Elemento<Inimigo>* ini;

public:
	GeradorProjeteis();
	~GeradorProjeteis();

	void CriarProjetil();
	void ExcluirProjetil();

	void iniciaGeradorProjeteis(ListaInimigos* li, ListaProjeteis* lp);


};

