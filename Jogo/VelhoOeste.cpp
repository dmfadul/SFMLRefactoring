#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(JogoInfo* pji, int n_jogadores)
	: Fase(pji, n_jogadores)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/velho_oeste.png");
	this->iniciarMapa("./Recursos/mapas/velho_oeste.txt", 1, 17);
	this->iniciarGerenciadorColisoes();
	this->iniciarGeradorProjeteis();
	this->jogoInfo->getTocaDisco()->tocarFallenDown();
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
	// atualiza jogadores
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog.getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		pJogador->atualizar();
		
		// checa se o jogador morreu
		//if (pJogador->getPersInfo()->getHp() <= 0)
			//this->listaJog.removerJogador(pJogador->getPersInfo()->getId());

		elJogador = elJogador->getProximo();
	}

	// atualiza inimigos
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		pInimigo->atualizar();
		elInimigo = elInimigo->getProximo();
	}

	if (this->listaJog.listaVazia()) 
		this->jogoInfo->popEnte();
	else
		this->gerColisoes.verificarColisoes();
	
	this->gerProj.CriarProjetil();
	this->gerColisoes.verificarColisoes();
}

// _______________________________________________________________________________
void VelhoOeste::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape){
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->popEnte(); // volta ao menu principal
		}
		if (evento_sfml.key.code == sf::Keyboard::K) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarEnte(new TelaMorte(this->jogoInfo, 100)); // tela de morte
		}
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
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

	//
	Lista<Projetil>::Elemento<Projetil>* elProjetil = this->listaProj.getPrimeiro();
	while (elProjetil != NULL) {
		Projetil* pProjetil = elProjetil->getInfo();
		pProjetil->desenharEntidade(janela);
		elProjetil = elProjetil->getProximo();
	}

	janela.draw(this->textoScore);

	this->mapa.desenharMapa(janela);
}

void VelhoOeste::iniciarInimigos()
{

	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(630.f, 410.f), 2700));
	//this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(370.f, 310.f), 140));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(510.f, 110.f), 1700));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(700.f, 50.f), 1950));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(1100.f, 280.f), 2800));

}