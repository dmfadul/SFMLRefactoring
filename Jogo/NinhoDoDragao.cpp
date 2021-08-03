#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji, int n_jogadores)
	: Fase(pji, n_jogadores)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/ninho_do_dragao.png");
	this->iniciarMapa("./Recursos/mapas/ninho_dragao.txt", 101, 17, 2);
	this->iniciarGerenciadorColisoes();
	this->jogoInfo->getTocaDisco()->tocarSpearOfJustice();
}

// _______________________________________________________________________________
NinhoDoDragao::~NinhoDoDragao()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizar()
{

	// atualiza jogadores
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog.getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		pJogador->atualizar();
		elJogador = elJogador->getProximo();
	}

	// atualiza inimigos
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		pInimigo->atualizar();
		elInimigo = elInimigo->getProximo();
	}

	this->gerColisoes.verificarColisoes();
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->popEnte(); // volta ao menu principal
		}
	}
}

// _______________________________________________________________________________
void NinhoDoDragao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.clear();
	janela.draw(this->background);

	// desenha jogadores 
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog.getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		pJogador->desenhar(janela);
		elJogador = elJogador->getProximo();
	}

	// desenha inimigos
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		pInimigo->desenhar(janela);
		elInimigo = elInimigo->getProximo();
	}

	janela.draw(this->textoScore);
	this->mapa.desenharMapa(janela);
	
}

void NinhoDoDragao::iniciarInimigos(){}
