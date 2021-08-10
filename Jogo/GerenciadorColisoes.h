#pragma once
#include "Mapa.h"
#include "Cowboy.h"
#include "HitBox.h"
#include "ListaJogadores.h"
#include "ListaInimigos.h"
#include "ListaProjeteis.h"
#include "ListaEntidades.h"

class GerenciadorColisoes
{
private:
	Mapa* mapa;
	ListaJogadores* listaJog;
	ListaInimigos* listaIni;
	ListaProjeteis* listaProj;
	ListaEntidades* listaEnt;

	void verificarColisao(Personagem* personagem, bool colidir_obstaculo = true);
	void verificarColisao(Jogador* jogador, Inimigo* inimigo);
	void verificarColisao(Jogador* jogador, Projetil* projetil);
	void verificarColisaoTela(Personagem* personagem);

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void iniciaGerenciadorColisoes(Mapa* m, ListaJogadores* lista_jog, ListaInimigos* lista_ini, ListaProjeteis* lista_proj, ListaEntidades* lista_ent);
	void verificarColisoes();

};

