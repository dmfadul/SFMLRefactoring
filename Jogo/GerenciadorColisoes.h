#pragma once
#include "Mapa.h"
#include "Cowboy.h"
#include "HitBox.h"
#include "ListaJogadores.h"
#include "ListaInimigos.h"

class GerenciadorColisoes
{
private:
	Mapa* mapa;
	ListaJogadores* listaJog;
	ListaInimigos* listaIni;

	void colisaoPersonagemPlataforma(Personagem* personagem, bool colidir_obstaculo = true);
	void colisaoPersonagemTela(Personagem* personagem);
	void colisaoPersonagemPersonagem();

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void iniciaGerenciadorColisoes(Mapa* m, ListaJogadores* lista_jog, ListaInimigos* lista_ini);
	void verificarColisoes();

};

