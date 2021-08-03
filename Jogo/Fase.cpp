#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji, int n_jogadores):
	Ente(pji), nJogadores(n_jogadores)
{
	this->iniciarTextoScore();
}

// _______________________________________________________________________________
Fase::~Fase()
{
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	listaJog.incluirJogador(new Cowboy("./Recursos/Imagens/Personagens/cowboy.png"));

	if(this->nJogadores == 2)
		listaJog.incluirJogador(new CowGirl("./Recursos/Imagens/Personagens/cowgirl.png"));

	iniciarInimigos();
}

// _______________________________________________________________________________
void Fase::iniciarMapa(std::string dir, int ini, int qtd, int tipo)
{
	this->mapa.iniciarMapa(dir, ini, qtd, tipo);
}

// _______________________________________________________________________________
void Fase::iniciarTextoScore()
{
	if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")) {
		std::cerr << "BOTAO::FALHA AO CARREGAR FONTE" << std::endl;
	}

	// Inicia texto
	this->textoScore.setString("Score: 0");
	this->textoScore.setFont(this->fonte);
	this->textoScore.setCharacterSize(38);
	this->textoScore.setPosition(
		TAM_JANELA_X / 2 - this->textoScore.getGlobalBounds().width / 2,
		10.f
	);
}

// _______________________________________________________________________________
void Fase::iniciarGerenciadorColisoes()
{
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->listaJog, &this->listaIni);
}
