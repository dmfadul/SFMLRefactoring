#include "stdafx.h"
#include "HitBox.h"

// _______________________________________________________________________________
HitBox::HitBox(sf::Sprite* s)
    :sprite(s)
{
    this->offsetX = 0;
    this->offsetY = 0;
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(1.f);

}

// _______________________________________________________________________________
HitBox::~HitBox()
{
    this->sprite = NULL;
}

// _______________________________________________________________________________
void HitBox::setSprite(sf::Sprite* s)
{
    this->sprite = s;
}

// _______________________________________________________________________________
void HitBox::setTamanho(const sf::Vector2f tam)
{
    this->hitbox.setSize(tam);
}

// _______________________________________________________________________________
void HitBox::setOffsetX(const int o)
{
    this->offsetX = o;
}

// _______________________________________________________________________________
void HitBox::setOffSetY(const int o)
{
    this->offsetY = o;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getEsquerda() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x;
    aux.y = this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height - 10.f;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getDireita() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x + this->hitbox.getGlobalBounds().width;
    aux.y = this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height - 10.f;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getCima() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x + this->hitbox.getGlobalBounds().width / 2.f;
    aux.y = this->hitbox.getPosition().y;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getCimaEsquerda() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x;
    aux.y = this->hitbox.getPosition().y;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getCimaDireita() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x;
    aux.y = this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().width;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getBaixoEsquerda() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x + 5.f;
    aux.y = this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height;
    return aux;
}

// _______________________________________________________________________________
const sf::Vector2f HitBox::getBaixoDireita() const
{
    sf::Vector2f aux;
    aux.x = this->hitbox.getPosition().x + this->hitbox.getGlobalBounds().width - 5.f;
    aux.y = this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height;
    return aux;
}

// _______________________________________________________________________________
const sf::FloatRect HitBox::getBounds() const { return this->hitbox.getGlobalBounds(); }

const float HitBox::getWidth() const { return this->hitbox.getGlobalBounds().width; }

const float HitBox::getHeight() const { return this->hitbox.getGlobalBounds().height; }

const int HitBox::getOffsetX() const { return this->offsetX; }

const int HitBox::getOffsetY() const { return this->offsetY; }

// _______________________________________________________________________________
void HitBox::atualizarPosicao()
{
    this->hitbox.setPosition(
        this->sprite->getPosition().x + this->offsetX,
        this->sprite->getPosition().y + this->offsetY
    );
}

// _______________________________________________________________________________
void HitBox::desenhar(sf::RenderTarget& janela)
{
    janela.draw(this->hitbox);
}
