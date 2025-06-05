#pragma once
#include "Utils/ListaEntidades.h"
#include "Utils/ListaInimigos.h"
#include "Utils/ListaJogadores.h"
#include "Utils/ListaProjeteis.h"
#include "Entities/Cowboy.h"
#include "Entities/CowGirl.h"
#include "Entities/Bruxa.h"
#include "Entities/Cobra.h"
#include "Entities/Morcego.h"
#include "Entities/Shuriken.h"
#include "Entities/Dragao.h"
#include "Entities/BolaFogo.h"

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

