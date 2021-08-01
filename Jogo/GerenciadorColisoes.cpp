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
		delete personagem;
	}
}

// _______________________________________________________________________________
void GerenciadorColisoes::colisaoPersonagemPersonagem()
{
	for (int i = 0; i < this->personagens->size(); i++) {
		for (int j = i + 1; j < this->personagens->size(); j++) {
			// se houver colisao entre dois personagens diferentes
			Personagem* p1 = this->personagens->at(i);
			Personagem* p2 = this->personagens->at(j);
			if (p1->getHitbox().getBounds().intersects(p2->getHitbox().getBounds())) {
				HitBox hitbox1 = p1->getHitbox();
				HitBox hitbox2 = p2->getHitbox();

				if (hitbox2.getDireita().x > hitbox1.getEsquerda().x) {
					p2->getMovComp()->acelerarX(p1->getMovComp()->getVelocidade().x / 4);
				}
				else {
					p1->getMovComp()->acelerarX(p2->getMovComp()->getVelocidade().x / 4);
				}
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
	for (auto& personagem : *this->personagens) {
		HitBox hitbox = personagem->getHitbox();

		// colisao da direita da hitbox com uma plataforma
		int bloco = this->mapa->blocoAtual(hitbox.getDireita()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir()) 
		{
			personagem->getMovComp()->setVelX(0.f);
			personagem->setPosicao(
				hitbox.getPosGridBaixoDir().x * TAM_BLOCO - hitbox.getOffsetDireita() - 0.1f,
				personagem->getPosition().y
			);
		}

		// colisao da esquerda da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getEsquerda()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir()) 
		{
			personagem->getMovComp()->setVelX(0.f);
			personagem->setPosicao(
				(hitbox.getPosGridCimaEsq().x + 1) * TAM_BLOCO - hitbox.getOffsetEsquerda(),
				personagem->getPosition().y
			);
		}

		// colisao da parte de cima da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(personagem->getHitbox().getCima()) - 1;
		if (bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir())
		{
			personagem->getMovComp()->setVelY(0.f);
			personagem->setPosicao(
				personagem->getPosition().x,
				(hitbox.getPosGridCimaEsq().y + 1) * TAM_BLOCO - hitbox.getOffsetCima()
			);
		}

		// colisao da parte de baixo da hitbox com uma plataforma
		bloco = this->mapa->blocoAtual(hitbox.getBaixoEsquerda()) - 1;
		int bloco2 = this->mapa->blocoAtual(hitbox.getBaixoDireita()) - 1;
		if ( bloco >= 0 && this->mapa->getEntidade(bloco)->getColidir() ||
			(bloco2 >= 0 && this->mapa->getEntidade(bloco2)->getColidir()) ) 
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
}

// _______________________________________________________________________________
void GerenciadorColisoes::colisaoPersonagemTela()
{
	for (auto& personagem : *this->personagens) {
		HitBox hitbox = personagem->getHitbox();
		// colisao com a direita da tela
		if (personagem->getHitbox().getDireita().x > TAM_JANELA_X) {
			personagem->getMovComp()->setVelX(0.f);
			personagem->setPosicao(
				TAM_JANELA_X - hitbox.getOffsetDireita(),
				personagem->getPosition().y);
		}

		// colisao com a esquerda da tela
		if (personagem->getHitbox().getEsquerda().x < 0) {
			personagem->getMovComp()->setVelX(0.f);
			personagem->setPosicao(
				-hitbox.getOffsetEsquerda(),
				personagem->getPosition().y);
		}
	}
}
