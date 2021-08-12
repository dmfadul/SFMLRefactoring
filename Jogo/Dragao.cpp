#include "stdafx.h"
#include "Dragao.h"

// _______________________________________________________________________________
Dragao::Dragao(sf::Vector2f position, GeradorProjeteis* gp)
	: Inimigo(), gerProj(gp)
{
	this->recompensa = 100;
	this->iniciarSprite("./Recursos/Imagens/Personagens/dragao.png", 0.25f, 0.25f);
	this->iniciarCompMov(0);
	this->iniciarPersInfo(VIDA_INICIAL_DRAGAO, DANO_ATAQUE);
	this->iniciarHitbox(textura.getSize().x * 0.20f, textura.getSize().y * 0.20f -10.f, 17.f, 13.f);
	this->sprite.setPosition(position);
	this->barraVida.setTam(100, 20);
	this->barraVida.setValorMaximo(VIDA_INICIAL_DRAGAO);
	this->nome = "DRAGAO";
}

Dragao::Dragao(): gerProj(NULL){}

// _______________________________________________________________________________
Dragao::~Dragao() {}


void Dragao::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	this->barraVida.desenharBarraVida(janela);
}
void Dragao::atualizar()
{
	this->getMovComp()->mover();
	this->hitbox.atualizarPosicao();
	this->barraVida.setPosicao(this->sprite.getPosition().x + 25.f, this->sprite.getPosition().y - 28.f);
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