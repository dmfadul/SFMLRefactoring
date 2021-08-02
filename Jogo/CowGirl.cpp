#include "stdafx.h"
#include "CowGirl.h"

// _______________________________________________________________________________
CowGirl::CowGirl(std::string imgCaminho)
{
	this->iniciarSprite(imgCaminho, 2.f, 2.f);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15.f, 25.f);
	this->iniciarCompMov(VEL_MAX_PLAYER);
}

// _______________________________________________________________________________
CowGirl::~CowGirl()
{
}

void CowGirl::mover()
{
	/* Movimenta o personagem de acordo com o input do usuario */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->compMov.acelerarX(-0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->compMov.acelerarX(0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->compMov.getCaindo() == false)
		this->compMov.setVelY(-13.f);
}

// _______________________________________________________________________________
void CowGirl::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

// _______________________________________________________________________________
void CowGirl::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	this->hitbox.desenhar(janela);
}
