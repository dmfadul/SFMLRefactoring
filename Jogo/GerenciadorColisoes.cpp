#include "stdafx.h"
#include "GerenciadorColisoes.h"

// _______________________________________________________________________________
GerenciadorColisoes::GerenciadorColisoes()
	:mapa(NULL), personagens(NULL)
{
}

// _______________________________________________________________________________
GerenciadorColisoes::~GerenciadorColisoes()
{
	mapa = NULL;
	for (auto personagem : *this->personagens) {
		personagem = NULL;
	}
	personagens = NULL;
}

// _______________________________________________________________________________
void GerenciadorColisoes::colisaoPersonagemPersonagem()
{
	for (auto& p1 : *this->personagens) {
		for (auto& p2 : *this->personagens) {
			// se houver colisao entre dois personagens diferentes
			if (p1->getId() != p2->getId() && p1->getHitbox().getBounds().intersects(p2->getHitbox().getBounds())) {
				/* Fazer Colisão. */
			}
		}
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::iniciaGerenciadorColisoes(Mapa* m, std::vector<Personagem* >* p)
{
	this->mapa = m;
	this->personagens = p;
}

// _______________________________________________________________________________
void GerenciadorColisoes::verificarColisoes()
{
	this->colisaoPersonagemPlataforma();
	this->colisaoPersonagemPersonagem();
	this->colisaoPersonagemTela();
}

// _______________________________________________________________________________
void GerenciadorColisoes::colisaoPersonagemPlataforma()
{
	int bloco = 0;
	for (auto& personagem : *this->personagens) {
		// colisao da direita da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getDireita()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir()) 
		{
			personagem->setVelX(0);
			personagem->setPosicao(
				((personagem->getPosition().x / TAM_BLOCO) * TAM_BLOCO) - personagem->getHitbox().getWidth() + personagem->getHitbox().getOffsetX(),
				personagem->getPosition().y
			);
		}

		// colisao da esquerda da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getEsquerda()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir()) 
		{
			personagem->setVelX(0);
			personagem->setPosicao(
				(personagem->getPosition().x / TAM_BLOCO) * TAM_BLOCO + personagem->getHitbox().getOffsetX(),
				personagem->getPosition().y
			);
		}

		// colisao da parte de cima da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getCima()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir())
		{
			personagem->setPosicao(
				personagem->getPosition().x,
				((personagem->getPosition().y / TAM_BLOCO) + 1) * TAM_BLOCO - personagem->getHitbox().getOffsetY()
			);
		}

		// colisao da parte de baixo da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getBaixoDireita()) - 1;
		int bloco2 = this->mapa->blocoAtual(personagem->getHitbox().getBaixoEsquerda()) - 1;
		if ( bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir() ||
			bloco2 >= 0 && this->mapa->getEntidade(bloco2)->getColidir() ) 
		{
			personagem->setVelY(0.f);
			personagem->setCaindo(false);
			personagem->setPosicao(
				personagem->getPosition().x,
				((personagem->getPosition().y / TAM_BLOCO) - 1) * TAM_BLOCO + personagem->getHitbox().getOffsetY() + 5.55f
			);
		}
		else {
			personagem->setCaindo(true);
		}
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::colisaoPersonagemTela()
{
	for (auto& personagem : *this->personagens) {
		// colisao com a direita da tela
		if (personagem->getHitbox().getDireita().x > TAM_JANELA_X) {
			personagem->setPosicao(
				TAM_JANELA_X - personagem->getBounds().width + personagem->getHitbox().getOffsetX(),
				personagem->getPosition().y);
		}

		// colisao com a esquerda da tela
		if (personagem->getHitbox().getEsquerda().x < 0) {
			personagem->setPosicao(
				-personagem->getHitbox().getOffsetX(),
				personagem->getPosition().y);
		}
	}
}
