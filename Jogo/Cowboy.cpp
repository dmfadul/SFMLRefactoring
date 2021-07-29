#include "stdafx.h"
#include "Cowboy.h"

// _______________________________________________________________________________
Cowboy::Cowboy()
{
}

// _______________________________________________________________________________
Cowboy::Cowboy(std::string imgCaminho)
{
	if (!texture.loadFromFile(imgCaminho))
	{
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(100.0,400.0));
	sprite.setScale(sf::Vector2f(2.0, 2.0));
	this->iniciarHitbox();
}

// _______________________________________________________________________________
void Cowboy::mover(char direcao, float velocidade)
{
	if (direcao == 'u')
	{
		sprite.move(0, -velocidade);
	}
	else if (direcao == 'd')
	{
		sprite.move(0, velocidade);
	}
	else if (direcao == 'l')
	{
		sprite.move(-velocidade, 0);
	}
	else if (direcao == 'r')
	{
		sprite.move(velocidade, 0);
	}
}

// _______________________________________________________________________________
void Cowboy::desenhar(sf::RenderTarget& janela)
{
	this->hitbox.desenhar(janela);
	janela.draw(sprite);
}

// _______________________________________________________________________________
void Cowboy::atualizar()
{

	this->hitbox.atualizarPosicao();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->mover('u', 6.0);
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->mover('l', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->mover('d', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->mover('r', 6.0);
	}
}

// _______________________________________________________________________________
bool Cowboy::verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push)
{
	float deltaX = posicao.x - sprite.getPosition().x;
	float deltaY = posicao.y - sprite.getPosition().y;

	float intersectX = abs(deltaX) - (tamanho.x / 2 + sprite.getTexture()->getSize().x * sprite.getScale().x / 2);
	float intersectY = abs(deltaY) - (tamanho.y / 2 + sprite.getTexture()->getSize().y * sprite.getScale().y / 2);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				this->mover('r', intersectX * push);
			}
			else
			{
				this->mover('l', intersectX * push);
			}
		}
		else
		{
			if (deltaX > 0.0f)
			{
				this->mover('u', intersectY * push);
			}
			else
			{
				this->mover('d', intersectY * push);
			}
		}

		return true;
	}

	return false;
}

// _______________________________________________________________________________
Cowboy::~Cowboy()
{
}
