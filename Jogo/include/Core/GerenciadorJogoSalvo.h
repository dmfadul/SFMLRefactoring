#pragma once
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "ListaJogadores.h"
#include "ListaProjeteis.h"
#include "Cowboy.h"
#include "CowGirl.h"
#include "Bruxa.h"
#include "Cobra.h"
#include "Morcego.h"
#include "Shuriken.h"
#include "Dragao.h"
#include "BolaFogo.h"

class GerenciadorJogoSalvo
{
private:
public:
	GerenciadorJogoSalvo();
	~GerenciadorJogoSalvo();

	void salvarEstadoDaFase(std::string nome_fase, int qtd_jogadores);
	void salvarJogadores(ListaJogadores* lp, int score);
	void salvarInimigos(ListaInimigos* li);
	void salvarProjeteis(ListaProjeteis* lp);

	void carregarJogadores(ListaJogadores* lj, ListaEntidades* le, ListaProjeteis* lp);
	void carregarInimigos(ListaInimigos* li, ListaEntidades* le, GeradorProjeteis* gp, ListaJogadores* lj);
	void carregarProjeteis(ListaProjeteis* lp, ListaEntidades* le);
};

