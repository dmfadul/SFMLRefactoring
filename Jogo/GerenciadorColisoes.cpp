#include "stdafx.h"
#include "GerenciadorColisoes.h"

// _______________________________________________________________________________
GerenciadorColisoes::GerenciadorColisoes()
	:mapa(NULL), listaJog(NULL), listaIni(NULL), listaProj(NULL)
{
}

// _______________________________________________________________________________
GerenciadorColisoes::~GerenciadorColisoes()
{
	this->mapa = NULL;
	this->listaJog = NULL;
	this->listaIni = NULL;
	this->listaProj = NULL;
}


// _______________________________________________________________________________
void GerenciadorColisoes::iniciaGerenciadorColisoes(Mapa* m, ListaJogadores* lista_jog, ListaInimigos* lista_ini, ListaProjeteis* lista_proj)
{
	this->mapa = m;
	this->listaJog = lista_jog;
	this->listaIni = lista_ini;
	this->listaProj = lista_proj;
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisoes()
{
	// colisoes do jogador
	Lista<Jogador>::Elemento<Jogador>* elJogador = this->listaJog->getPrimeiro();
	while (elJogador != NULL) {
		Jogador* pJogador = elJogador->getInfo();
		
		//this->verificarColisao(static_cast<Personagem*>(pJogador));
		this->verificarColisao(static_cast<Personagem*>(pJogador), true);
		this->verificarColisaoTela(static_cast<Personagem*>(pJogador));

		// colisoes do jogador com projetil
		Lista<Projetil>::Elemento<Projetil>* elProj = listaProj->getPrimeiro();
		while (elProj != NULL){
			Projetil* pProjetil = elProj->getInfo();
			verificarColisao(pJogador, pProjetil);
			elProj = elProj->getProximo();
		}

		// colisoes do jogador com inimigo
		Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni->getPrimeiro();
		while (elInimigo != NULL) {
			Inimigo* pInimigo = elInimigo->getInfo();
			this->verificarColisao(pJogador, pInimigo);
			elInimigo = elInimigo->getProximo();
		}

		elJogador = elJogador->getProximo();
	}

	// colisoes do inimigo com plataforma e tela
	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni->getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();

		this->verificarColisao(static_cast<Personagem*>(pInimigo), false);
		this->verificarColisaoTela(static_cast<Personagem*>(pInimigo));
		elInimigo = elInimigo->getProximo();
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
		Obstaculo* obstaculo = static_cast<Obstaculo*>(this->mapa->getBloco(bloco));
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
		Obstaculo* obstaculo = static_cast<Obstaculo*>(this->mapa->getBloco(bloco));
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
		Obstaculo* obstaculo = static_cast<Obstaculo* >(this->mapa->getBloco(bloco));
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

void GerenciadorColisoes::verificarColisao(Jogador* jogador, Projetil* projetil)
{
	float raioPersonagem = jogador->getHitbox().getRaio();
	sf::Vector2f posicaoPersonagem = jogador->getHitbox().getPosition();
	sf::Vector2f posicaoProjetil;
	float raioProjetil;
	float distanciaTotal, distanciaX, distanciaY;
	
	raioProjetil = projetil->getHitbox().getRaio();
	posicaoProjetil = projetil->getHitbox().getPosition();
	distanciaX = posicaoPersonagem.x - posicaoProjetil.x;
	distanciaY = posicaoPersonagem.y - posicaoProjetil.y;
	distanciaTotal = sqrt(distanciaX * distanciaX + distanciaY * distanciaY);
	if (distanciaTotal < raioProjetil + raioPersonagem)
	{
		jogador->receberDano(projetil->getDano());
		listaProj->excluirProjetil(projetil->getId());

	} else

	if (posicaoProjetil.y < 0 || posicaoProjetil.y > TAM_JANELA_Y)
	{
		listaProj->excluirProjetil(projetil->getId());
	} else

	if (posicaoProjetil.x < 0 || posicaoProjetil.x > TAM_JANELA_X)
	{
		listaProj->excluirProjetil(projetil->getId());
	}
}