#include "stdafx.h"
#include "Cowboy.h"

// _______________________________________________________________________________
Cowboy::Cowboy(std::string imgCaminho)
{
	if (!texture.loadFromFile(imgCaminho))
	{
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(100.0,100.0));
	sprite.setScale(sf::Vector2f(2.0, 2.0));
	this->iniciarHitbox();
	this->iniciarCompMov();
}

// _______________________________________________________________________________
void Cowboy::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
}

// _______________________________________________________________________________
void Cowboy::atualizar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->compMov.acelerarX(-0.2f);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->compMov.acelerarX(0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->compMov.getCaindo() == false)
		this->compMov.setVelY(-13.f);

	this->hitbox.atualizarPosicao();
	this->compMov.mover();
}

// _______________________________________________________________________________
Cowboy::~Cowboy()
{
}
