#include "stdafx.h"
#include "Fase.h"

// _______________________________________________________________________________
Fase::Fase(JogoInfo* pji, int n_jogadores):
	Ente(pji), nJogadores(n_jogadores)
{
	this->iniciarTextoScore();
	this->pausado = false;
}

// _______________________________________________________________________________
Fase::~Fase()
{
	Lista<Inimigo>::Elemento<Inimigo>* elIni = listaIni.getPrimeiro();
	while (elIni != NULL) {
		listaEntidades.removerEntidade(elIni->getId());
		elIni = elIni->getProximo();
		
	}
}

// _______________________________________________________________________________
void Fase::iniciarPersonagens()
{
	/* Adiciona todas os personagens em suas respectivas listas */
	Cowboy* jogador1 = new Cowboy(&this->listaProj, &this->listaEntidades);
	this->listaJog.incluirJogador(jogador1);
	this->listaEntidades.incluirEntidade(static_cast<Entidade* >(jogador1));


	if (this->nJogadores == 2) {
		CowGirl* jogador2 = new CowGirl(&this->listaProj, &this->listaEntidades);
		this->listaJog.incluirJogador(jogador2);
		this->listaEntidades.incluirEntidade(static_cast<Entidade*>(jogador2));
	}

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
	this->gerColisoes.iniciaGerenciadorColisoes(&this->mapa, &this->listaJog, &this->listaIni, &this->listaProj, &this->listaEntidades);
}

// _______________________________________________________________________________
void Fase::iniciarGeradorProjeteis()
{
	this->gerProj.iniciaGeradorProjeteis(&this->listaIni, &this->listaProj, &this->listaEntidades);
}

// _______________________________________________________________________________
void Fase::atualizarEntidades()
{
	// atualiza jogadores
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog.getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		pJogador->atualizar();
		elJogador = elJogador->getProximo();
		// checa se o jogador morreu
		if (pJogador->getPersInfo()->getHp() <= 0) {
			this->listaJog.removerJogador(pJogador->getId());
			this->listaEntidades.removerEntidade(pJogador->getId());
		}

	}

	// atualiza inimigos
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		elInimigo = elInimigo->getProximo();
		pInimigo->atualizar();
		// checa se o inimigo morreu
		if (pInimigo->getPersInfo()->getHp() <= 0) {
			this->listaIni.removerInimigo(pInimigo->getId());
			this->listaEntidades.removerEntidade(pInimigo->getId());
			this->atualizarScore(pInimigo->getRecompensa());
		}
	}

	Lista<Projetil>::Elemento<Projetil>* elProjetil = this->listaProj.getPrimeiro();
	while (elProjetil != NULL) {
		Projetil* pProjetil = elProjetil->getInfo();
		elProjetil = elProjetil->getProximo();
		pProjetil->atualizar();
	}

}

void Fase::atualizarScore(int incremento)
{
	// incrementa score do jogador
	int pontuacao = PersonagemInfo::getScore();
	PersonagemInfo::setScore(pontuacao + incremento);

	// atualiza o texto de score
	std::string textoPontuacao = "SCORE: " + std::to_string(pontuacao + incremento);
	this->textoScore.setTexto(textoPontuacao);
}

void Fase::desenharEntidades(sf::RenderTarget& janela)
{
	// desenha entidades 
	Lista<Entidade>::Elemento<Entidade>* elEntidade = this->listaEntidades.getPrimeiro();
	while (elEntidade != NULL) {
		Entidade* pEntidade = elEntidade->getInfo();
		elEntidade = elEntidade->getProximo();
		pEntidade->desenhar(janela);
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
		this->jogoInfo->popEnte();
		PersonagemInfo::setScore(0);
	}
}
