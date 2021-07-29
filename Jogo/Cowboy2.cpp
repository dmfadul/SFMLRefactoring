#include "stdafx.h"
#include "Cowboy2.h"

Cowboy2::Cowboy2()
{
}

Cowboy2::Cowboy2(std::string imgCaminho)
{
	if (!texture.loadFromFile(imgCaminho))
	{
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(100.0, 400.0));
	sprite.setScale(sf::Vector2f(2.0, 2.0));
	this->iniciarHitbox();
}

void Cowboy2::mover(char direcao, float velocidade)
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

void Cowboy2::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	this->hitbox.desenhar(janela);
}

void Cowboy2::atualizar()
{
	this->hitbox.atualizarPosicao();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->mover('u', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->mover('d', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->mover('r', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->mover('l', 6.0);
	}
}

bool Cowboy2::verificarColisao(sf::Vector2f posicao, sf::Vector2f tamanho, float push)
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

sf::Vector2f Cowboy2::getPosition()
{
	return sprite.getPosition();
}

sf::Vector2f Cowboy2::getSize()
{
	return sf::Vector2f(sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
}

Cowboy2::~Cowboy2()
{
}
