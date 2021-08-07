#include "stdafx.h"
#include "CowGirl.h"

// _______________________________________________________________________________
CowGirl::CowGirl()
{
	this->iniciarSprite("./Recursos/Imagens/Personagens/cowgirl.png", 2.f, 2.f);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_PLAYER);
	this->barraVida.setTamTexto(22);
	this->barraVida.setPosicao(TAM_JANELA_X - 190.f, 40.f);
	this->barraVida.identificarBarra("Cowgirl", TAM_JANELA_X - 70.f, 10.f);
	this->barraVida.setValorMaximo(VIDA_INICIAL);
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
	this->barraVida.desenharBarra(janela);
	this->hitbox.desenhar(janela);
}
