#include "Core/stdafx.h"
#include "Utils/HitBox.h"

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
    this->sprite = 0;
}

// _______________________________________________________________________________
void HitBox::setSprite(sf::Sprite* s) { this->sprite = s; }

void HitBox::setTamanho(const sf::Vector2f tam) { this->hitbox.setSize(tam); }

void HitBox::setOffsetX(const int o) { this->offsetX = o; }

void HitBox::setOffSetY(const int o) { this->offsetY = o; }

sf::FloatRect HitBox::getBounds() { return this->hitbox.getGlobalBounds(); }

// _______________________________________________________________________________
sf::Vector2i HitBox::getPosGridCimaEsq()
{
    return sf::Vector2i((int)(this->hitbox.getPosition().x/ TAM_BLOCO), (int)(this->hitbox.getPosition().y) / TAM_BLOCO);
}

sf::Vector2i HitBox::getPosGridBaixoDir()
{
    return sf::Vector2i(
        ((int)(this->hitbox.getPosition().x + this->hitbox.getGlobalBounds().width)) / TAM_BLOCO,
        ((int)(this->hitbox.getPosition().y + this->hitbox.getGlobalBounds().height)) / TAM_BLOCO
    );
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
    aux.y = this->hitbox.getPosition().y ;
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
const int HitBox::getOffsetCima() const
{
        return offsetY;
}

// _______________________________________________________________________________
const int HitBox::getOffsetBaixo() const
{
    return (int)(this->hitbox.getGlobalBounds().height) + this->offsetY;
}

// _______________________________________________________________________________
const int HitBox::getOffsetEsquerda() const
{
    return this->offsetX;
}

// _______________________________________________________________________________
const int HitBox::getOffsetDireita() const
{
    return this->offsetX + (int)(this->hitbox.getGlobalBounds().width);
}

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

// _______________________________________________________________________________
sf::Vector2f HitBox::getPosition()
{
    return hitbox.getPosition();
}