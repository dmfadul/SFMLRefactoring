#include "stdafx.h"
#include "Cowboy.h"

Cowboy::Cowboy()
{
}

Cowboy::Cowboy(std::string imgDirectory)
{
	if (!texture.loadFromFile(imgDirectory))
	{
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0.0,400.0));
}

void Cowboy::move(char direction, float speed)
{
	if (direction == 'u')
	{
		sprite.move(0, -speed);
	}
	else if (direction == 'd')
	{
		sprite.move(0, speed);
	}
	else if (direction == 'l')
	{
		sprite.move(-speed, 0);
	}
	else if (direction == 'r')
	{
		sprite.move(speed, 0);
	}
}

void Cowboy::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
}

void Cowboy::atualizar()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move('u', 6.0);
	} 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move('l', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move('d', 6.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move('r', 6.0);
	}
}

Cowboy::~Cowboy()
{
}
