#include "stdafx.h"
#include "Bruxa.h"

Bruxa::Bruxa(std::string imgCaminho):
tempo_vida(0), direction(true){
	this->iniciarSprite(imgCaminho, 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15.f, 25.f);
	this->iniciarCompMov(VEL_MAX_PLAYER);

	// APAGAR
	std::cout << "Vida Inicial: " << pInfo.getHp() << std::endl;
	std::cout << "Dano: " << pInfo.getDano() << std::endl;
}

Bruxa::~Bruxa(){}

void Bruxa::mover()
{
	if (tempo_vida == 50) {
		direction = !direction;
		tempo_vida = 0;
	}
	
	if (direction)
		this->compMov.acelerarX(-0.2f);
	else
		this->compMov.acelerarX(0.2f);
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