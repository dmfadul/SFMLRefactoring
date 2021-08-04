#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji, int n_jogadores):
	Tela(pji), nJogadores(n_jogadores)
{
	this->iniciarTextoScore();
	this->pausado = false;
}

// _______________________________________________________________________________
Fase::~Fase()
{
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	listaJog.incluirJogador(new Cowboy("./Recursos/Imagens/Personagens/cowboy.png"));

	if (this->nJogadores == 2)
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
	this->textoScore.iniciarTexto(0, 0, "SCORE: 0");
	this->textoScore.getTexto()->setCharacterSize(38);
	this->textoScore.getTexto()->setPosition(
		TAM_JANELA_X / 2 - this->textoScore.getTexto()->getGlobalBounds().width / 2,
		10.f
	);
}

// _______________________________________________________________________________
void Fase::iniciarGerenciadorColisoes()
{
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->listaJog, &this->listaIni);
}

void Fase::iniciarGeradorProjeteis()
{
	this->gerProj.iniciaGeradorProjeteis(&this->listaIni, &this->listaProj);
}

void Fase::atualizarEntidades()
{
	// atualiza jogadores
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog.getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		pJogador->atualizar();

		// checa se o jogador morreu
		if (pJogador->getPersInfo()->getHp() <= 0)
			this->listaJog.removerJogador(pJogador->getId());

		elJogador = elJogador->getProximo();
	}

	// atualiza inimigos
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		pInimigo->atualizar();
		elInimigo = elInimigo->getProximo();
	}

}

void Fase::desenharEntidades(sf::RenderTarget& janela)
{
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

	// desenha projeteis
	Lista<Projetil>::Elemento<Projetil>* elProjetil = this->listaProj.getPrimeiro();
	while (elProjetil != NULL) {
		Projetil* pProjetil = elProjetil->getInfo();
		pProjetil->desenharProjetil(janela);
		elProjetil = elProjetil->getProximo();
	}
}

void Fase::realizarAcaoMenuPause()
{
	/* Realiza a ação vinculada com o botao ativo */
	int botao_ativo = this->caixaPause.getBotaoAtivo();
	if (botao_ativo == continuar) {
		this->pausado = false;
	}

	else if (botao_ativo == salvar_partida) {
		/* IMPLEMENTAR */
	}

	else if (botao_ativo == voltar) {
		this->jogoInfo->getTocaDisco()->pararMusica();
		this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
		this->jogoInfo->popTela();
	}
}
