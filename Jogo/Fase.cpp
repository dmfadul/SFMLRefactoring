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
	for (auto& personagem : this->personagens)
		delete personagem;
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	this->personagens.push_back(new Cowboy("./Recursos/Imagens/Personagens/Cowboy.png"));
	this->personagens.push_back(new CowGirl("./Recursos/Imagens/Personagens/Cowgirl.png"));
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
