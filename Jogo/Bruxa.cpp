#include "stdafx.h"
#include "Bruxa.h"

Bruxa::Bruxa():tempo_vida(0), direction(true) {}

Bruxa::Bruxa(std::string imgCaminho, sf::Vector2f position, int tempo_direcao):
tempo_vida(0), direction(true), tempo_direcao(tempo_direcao){
	this->iniciarSprite(imgCaminho, 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15.f, 25.f);
	this->iniciarCompMov(VEL_MAX_BRUXA);
	this->sprite.setPosition(position);

	// APAGAR
	std::cout << "Vida Inicial: " << pInfo.getHp() << std::endl;
	std::cout << "Dano: " << pInfo.getDano() << std::endl;
}

Bruxa::~Bruxa(){}

void Bruxa::mover()
{
	if (tempo_vida == tempo_direcao) {
		direction = !direction;
		tempo_vida = 0;
	}
	
	if (direction)
		this->compMov.acelerarX(-100.f);
	else
		this->compMov.acelerarX(100.f);
	tempo_vida++;
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