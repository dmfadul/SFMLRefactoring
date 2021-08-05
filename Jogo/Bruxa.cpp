#include "stdafx.h"
#include "Bruxa.h"

Bruxa::Bruxa(): tempo_direcao(1000) {}

Bruxa::Bruxa(std::string imgCaminho, sf::Vector2f position, int tempo_direcao):
tempo_direcao(tempo_direcao){
	this->iniciarSprite(imgCaminho, 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_BRUXA);
	this->sprite.setPosition(position);
	this->compMov.setControleArrasto(false);

	// APAGAR
	std::cout << "Vida Inicial: " << pInfo.getHp() << std::endl;
	std::cout << "Dano: " << pInfo.getDano() << std::endl;
}

Bruxa::~Bruxa(){}

void Bruxa::mover()
{
	if (this->tempo_vida.getElapsedTime().asMilliseconds() > tempo_direcao) {
		direction = !direction;
		tempo_vida.restart();
	}
	
	if (direction)
		this->compMov.setVelX(-VEL_MAX_BRUXA);
	else
		this->compMov.setVelX(VEL_MAX_BRUXA);
}

// _______________________________________________________________________________
void Bruxa::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

// _______________________________________________________________________________
void Bruxa::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	hitbox.desenhar(janela);
}

bool Bruxa::getDirection()
{
	return this->direction;
}