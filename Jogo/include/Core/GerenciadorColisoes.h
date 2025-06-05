#pragma once
#include "Levels/Mapa.h"
#include "Entities/Cowboy.h"
#include "Utils/HitBox.h"
#include "Utils/ListaJogadores.h"
#include "Utils/ListaInimigos.h"
#include "Utils/ListaProjeteis.h"
#include "Utils/ListaEntidades.h"

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
	void verificarColisao(Inimigo* inimigo, Projetil* projetil);
	void verificarColisaoTela(Personagem* personagem);

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void iniciaGerenciadorColisoes(Mapa* m, ListaJogadores* lista_jog, ListaInimigos* lista_ini, ListaProjeteis* lista_proj, ListaEntidades* lista_ent);
	void verificarColisoes();

};

