#pragma once
#include "Mapa.h"
#include "Cowboy.h"
class GerenciadorColisoes
{
private:
	Mapa* mapa;
	std::vector<Personagem* >* personagens;

	void colisaoPersonagemPlataforma();
	void colisaoPersonagemTela();
	void colisaoPersonagemPersonagem();

public:
	GerenciadorColisoes();
	~GerenciadorColisoes();

	void iniciaGerenciadorColisoes(Mapa* m, std::vector<Personagem* >* p);
	void verificarColisoes();

};

