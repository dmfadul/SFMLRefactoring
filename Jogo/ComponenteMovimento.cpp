#include "stdafx.h"
#include "ComponenteMovimento.h"

// _______________________________________________________________________________
ComponenteMovimento::ComponenteMovimento():
    sprite(NULL),
    gravidade(GRAVIDADE),
    caindo(true),
    vel(sf::Vector2f(0.f, 0.f)),
    velMax(0)
{
}

// _______________________________________________________________________________
ComponenteMovimento::~ComponenteMovimento()
{
    this->sprite = NULL;
}

// _______________________________________________________________________________
void ComponenteMovimento::iniciarCompMov(sf::Sprite* sprite, float vel_max)
{
    this->sprite = sprite;
    this->velMax = vel_max;
}

// _______________________________________________________________________________
void ComponenteMovimento::setVelX(float x) { this->vel.x = x; }

void ComponenteMovimento::setVelY(float y) { this->vel.y = y; }

void ComponenteMovimento::setCaindo(const bool c) { this->caindo = c; }

// _______________________________________________________________________________
const bool ComponenteMovimento::getCaindo() const { return this->caindo; }

sf::Vector2f ComponenteMovimento::getVelocidade() { return this->vel; }

// _______________________________________________________________________________
void ComponenteMovimento::acelerarX(float x) {
    if(this->vel.x < this->velMax && this->vel.x > - this->velMax) 
        this->vel.x += x; 
    if (this->vel.x > this->velMax)
        this->vel.x = this->velMax;
    if (this->vel.x < -this->velMax)
        this->vel.x = -this->velMax;
}

// _______________________________________________________________________________
void ComponenteMovimento::acelerarY(float y) {
    if (this->vel.y < VEL_MAX_QUEDA && this->vel.y > -VEL_MAX_QUEDA)
        this->vel.y += y; 
}

// _______________________________________________________________________________
void ComponenteMovimento::mover()
{
    // movimento na direção x
    if      (this->vel.x > 0.1f)   this->vel.x -= (float)(ARRASTO);
    else if (this->vel.x < -0.1f)  this->vel.x += (float)(ARRASTO);
    else                            this->vel.x = 0;

    // movimento na direção y
    if      (this->vel.y > 0.1f)   this->vel.y -= (float)(ARRASTO);
    else if (this->vel.y < -0.1f)  this->vel.y += (float)(ARRASTO);
    else                            this->vel.y = 0;

    // movimento em queda livre
    if (this->caindo && this->vel.y < (float)(VEL_MAX_QUEDA))   
       this->vel.y += (float)(GRAVIDADE);

    // executa o movimento
    this->sprite->move(this->vel);
}
