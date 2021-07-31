#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji):
	Ente(pji)
{
}

// _______________________________________________________________________________
Fase::~Fase()
{
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	this->personagens.push_back(new Cowboy("./Recursos/Imagens/Personagens/Cowboy/tile000.png"));
	this->personagens.push_back(new Cowboy2("./Recursos/Imagens/Personagens/Cowboy/tile000.png"));
}

// _______________________________________________________________________________
void Fase::iniciarMapa(std::string dir, int ini, int qtd)
{
	this->mapa.iniciarMapa(dir, ini, qtd);
}

// _______________________________________________________________________________
void Fase::iniciarGerenciadorColisoes()
{
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->personagens);
}
