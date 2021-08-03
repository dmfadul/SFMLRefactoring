#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji):
	Ente(pji)
{
	this->iniciarTextoScore();
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
	this->personagens.push_back(new Cowboy("./Recursos/Imagens/Personagens/cowboy.png"));
	this->personagens.push_back(new CowGirl("./Recursos/Imagens/Personagens/cowgirl.png"));
	listaPers.incluirJogador(new Cowboy("./Recursos/Imagens/Personagens/cowboy.png"));
	listaPers.incluirJogador(new CowGirl("./Recursos/Imagens/Personagens/cowgirl.png"));

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
		std::cout << "BOTAO::FALHA AO CARREGAR FONTE" << std::endl;
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
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->personagens);
}
