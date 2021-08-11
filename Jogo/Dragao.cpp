#include "stdafx.h"
#include "Dragao.h"

// _______________________________________________________________________________
Dragao::Dragao(sf::Vector2f position, GeradorProjeteis* gp)
	: Inimigo(), gerProj(gp)
{
	this->recompensa = 100;
	this->iniciarSprite("./Recursos/Imagens/Personagens/dragao.png", 0.25f, 0.25f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(textura.getSize().x * 0.25f, textura.getSize().y * 0.25f -10, 0, -10);
	this->sprite.setPosition(position);
}

Dragao::Dragao(): gerProj(NULL){}

// _______________________________________________________________________________
Dragao::~Dragao() {}


void Dragao::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	hitbox.desenhar(janela);
}
void Dragao::atualizar()
{
	this->hitbox.atualizarPosicao();
	if (this->cooldown_atirar.getElapsedTime().asMilliseconds() > 500) {
		this->cuspirFogo();
		this->cooldown_atirar.restart();
	}
}

void Dragao::cuspirFogo()
{
	this->gerProj->CriarProjetil(new BolaFogo(this->getHitbox().getCima(), true));
}

int Dragao::getTipo()
{
	return 3;
}