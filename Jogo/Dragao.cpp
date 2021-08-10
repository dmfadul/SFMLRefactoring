#include "stdafx.h"
#include "Dragao.h"

// _______________________________________________________________________________
Dragao::Dragao(sf::Vector2f position)
{
	this->iniciarSprite("./Recursos/Imagens/Personagens/dragao.png", 0.25f, 0.25f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(textura.getSize().x * 0.25f, textura.getSize().y * 0.25f -10, 0, -10);
	this->sprite.setPosition(position);
}

Dragao::Dragao(){}

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
}

int Dragao::getTipo()
{
	return 3;
}