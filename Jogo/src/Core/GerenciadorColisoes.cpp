#include "Core/stdafx.h"
#include "Core/GerenciadorColisoes.h"

// _______________________________________________________________________________
GerenciadorColisoes::GerenciadorColisoes()
	:mapa(NULL), listaJog(NULL), listaIni(NULL), listaProj(NULL), listaEnt(NULL)
{
}

// _______________________________________________________________________________
GerenciadorColisoes::~GerenciadorColisoes()
{
	this->mapa = 0;
	this->listaJog = 0;
	this->listaIni = 0;
	this->listaProj = 0;
	this->listaEnt = 0;
}


// _______________________________________________________________________________
void GerenciadorColisoes::iniciaGerenciadorColisoes(Mapa* m, ListaJogadores* lista_jog, ListaInimigos* lista_ini, ListaProjeteis* lista_proj, ListaEntidades* lista_ent)
{
	this->mapa = m;
	this->listaJog = lista_jog;
	this->listaIni = lista_ini;
	this->listaProj = lista_proj;
	this->listaEnt = lista_ent;
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisoes()
{
	// colisoes do jogador
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog->getPrimeiro();
	while (elJogador != 0) {
		Jogador* pJogador = elJogador->getInfo();
		elJogador = elJogador->getProximo();
		
		this->verificarColisao(static_cast<Personagem*>(pJogador), true);
		this->verificarColisaoTela(static_cast<Personagem*>(pJogador));

		// colisoes do jogador com projetil
		Lista<Projetil>::Elemento<Projetil>* elProj = listaProj->getPrimeiro();
		while (elProj != 0){
			Projetil* pProjetil = elProj->getInfo();
			elProj = elProj->getProximo();
			verificarColisao(pJogador, pProjetil);
		}

		// colisoes do jogador com inimigo
		Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni->getPrimeiro();
		while (elInimigo != 0) {
			Inimigo* pInimigo = elInimigo->getInfo();
			elInimigo = elInimigo->getProximo();
			this->verificarColisao(pJogador, pInimigo);
		}

	}

	// colisoes do inimigo com plataforma e tela
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni->getPrimeiro();
	while (elInimigo != 0) {
		Inimigo* pInimigo = elInimigo->getInfo();
		elInimigo = elInimigo->getProximo();
		this->verificarColisao(static_cast<Personagem*>(pInimigo), false);
		this->verificarColisaoTela(static_cast<Personagem*>(pInimigo));

		// colisoes do inimigo com projetil
		Lista<Projetil>::Elemento<Projetil>* elProj = listaProj->getPrimeiro();
		while (elProj != 0) {
			Projetil* pProjetil = elProj->getInfo();
			elProj = elProj->getProximo();
			verificarColisao(pInimigo, pProjetil);
		}
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisao(Personagem* personagem, bool colidir_obstaculo)
{
	/* Colisoes entre o personagem e obstaculos */
	HitBox hitbox = personagem->getHitbox();

	// colisao da direita da hitbox com uma plataforma
	int bloco = this->mapa->blocoAtual(hitbox.getDireita()) - 1;
	if (bloco >= 17 && colidir_obstaculo) {
		ObstaculoDanoso* obstaculo = static_cast<ObstaculoDanoso*>(this->mapa->getBloco(bloco));
		obstaculo->realizarAcao(static_cast<Jogador*>(personagem));
	}
	else if (bloco >= 0 && this->mapa->getBloco(bloco)->getColidir()) 
	{
		personagem->getMovComp()->setVelX(0.f);
		personagem->setPosicao(
			hitbox.getPosGridBaixoDir().x * TAM_BLOCO - hitbox.getOffsetDireita() - 0.1f,
			personagem->getPosition().y
		);
	}

	// colisao da esquerda da hitbox com uma plataforma
	bloco = this->mapa->blocoAtual(personagem->getHitbox().getEsquerda()) - 1;
	if (bloco >= 17 && colidir_obstaculo) {
		ObstaculoDanoso* obstaculo = static_cast<ObstaculoDanoso*>(this->mapa->getBloco(bloco));
		obstaculo->realizarAcao(static_cast<Jogador*>(personagem));
	}
	else if (bloco >= 0 && this->mapa->getBloco(bloco)->getColidir()) 
	{
		personagem->getMovComp()->setVelX(0.f);
		personagem->setPosicao(
			(float)((hitbox.getPosGridCimaEsq().x + 1) * TAM_BLOCO - hitbox.getOffsetEsquerda()),
			personagem->getPosition().y
		);
	}

	// colisao da parte de cima da hitbox com uma plataforma
	bloco = this->mapa->blocoAtual(personagem->getHitbox().getCima()) - 1;
	if (bloco >= 0 && this->mapa->getBloco(bloco)->getColidir())
	{
		personagem->getMovComp()->setVelY(0.f);
		personagem->setPosicao(
			personagem->getPosition().x,
			(float)((hitbox.getPosGridCimaEsq().y + 1) * TAM_BLOCO - hitbox.getOffsetCima())
		);
	}

	// colisao da parte de baixo da hitbox com uma plataforma
	bloco = this->mapa->blocoAtual(hitbox.getBaixoEsquerda()) - 1;
	int bloco2 = this->mapa->blocoAtual(hitbox.getBaixoDireita()) - 1;

	if (bloco >= 17 && colidir_obstaculo) {
		ObstaculoDanoso* obstaculo = static_cast<ObstaculoDanoso* >(this->mapa->getBloco(bloco));
		obstaculo->realizarAcao(static_cast<Jogador*>(personagem));
	}
	else if ( bloco >= 0 && this->mapa->getBloco(bloco)->getColidir() ||
		(bloco2 >= 0 && this->mapa->getBloco(bloco2)->getColidir()) ) 
	{
		personagem->getMovComp()->setVelY(0.f);
		personagem->getMovComp()->setCaindo(false);
		personagem->setPosicao(
			personagem->getPosition().x,
			hitbox.getPosGridBaixoDir().y * TAM_BLOCO - hitbox.getOffsetBaixo() - 0.1f
		);
	}
	else {
		personagem->getMovComp()->setCaindo(true);
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisao(Jogador* jogador, Inimigo* inimigo)
{
	/*Colisao entre inimigos e personagens*/
	if (jogador->getHitbox().getBounds().intersects(inimigo->getHitbox().getBounds())) {
		jogador->receberDano(15);
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisaoTela(Personagem* personagem)
{
	/* Colisao do persoangem com a tela */
	HitBox hitbox = personagem->getHitbox();
	// colisao com a direita da tela
	if (personagem->getHitbox().getDireita().x > TAM_JANELA_X) {
		personagem->getMovComp()->setVelX(0.f);
		personagem->setPosicao(
			(float)(TAM_JANELA_X - hitbox.getOffsetDireita()),
			personagem->getPosition().y);
	}

	// colisao com a esquerda da tela
	if (personagem->getHitbox().getEsquerda().x < 0) {
		personagem->getMovComp()->setVelX(0.f);
		personagem->setPosicao(
			float(-hitbox.getOffsetEsquerda()),
			personagem->getPosition().y);
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisao(Jogador* jogador, Projetil* projetil)
{
	/* Verifica colis�o do projetil com o jogador */
	sf::Vector2f posicaoProjetil = projetil->getHitbox().getPosition();
	bool remover = false;

	// colisao do projetil com jogador
	if (projetil->getHitbox().getBounds().intersects(jogador->getHitbox().getBounds()) &&
		projetil->getAtirador() == "INIMIGO")
	{
		remover = true;
		jogador->receberDano(projetil->getDano());
	}

	// colisao do projeitl com a tela
	else if (posicaoProjetil.y < 0 || posicaoProjetil.y > TAM_JANELA_Y) {
		remover = true;
	}

	else if (posicaoProjetil.x < 0 || posicaoProjetil.x > TAM_JANELA_X) {
		remover = true;
	}

	// colisao do projetil com o cenario
	int bloco = this->mapa->blocoAtual(projetil->getHitbox().getDireita()) - 1;
	int bloco2 = this->mapa->blocoAtual(projetil->getHitbox().getEsquerda()) - 1;
	if ((bloco >= 0 && this->mapa->getBloco(bloco)->getColidir())||
		(bloco2 >= 0 && this->mapa->getBloco(bloco2)->getColidir())) {
		remover = true;
	}

	if (remover){
		this->listaEnt->removerEntidade(projetil->getId());
		this->listaProj->excluirProjetil(projetil->getId());
	}
	
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisao(Inimigo* inimigo, Projetil* projetil)
{
	/*Verifica Colisao do Projetil com inimigo*/
	sf::Vector2f posicaoProjetil = projetil->getHitbox().getPosition();
	if (projetil->getHitbox().getBounds().intersects(inimigo->getHitbox().getBounds()) &&
		projetil->getAtirador() == "JOGADOR")
	{
		this->listaEnt->removerEntidade(projetil->getId());
		this->listaProj->excluirProjetil(projetil->getId());
		inimigo->receberDano(projetil->getDano());
	}
}
