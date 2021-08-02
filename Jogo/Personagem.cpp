#include "stdafx.h"
#include "Personagem.h"

// _______________________________________________________________________________
Personagem::Personagem():
hitbox(),
compMov(),
pInfo(),
barraVida()
{}

// _______________________________________________________________________________
Personagem::~Personagem(){}

// _______________________________________________________________________________
void Personagem::iniciarSprite(std::string imgCaminho, float scale_x, float scale_y)
{
	/* Inicia o sprite do personagem */
	if (!texture.loadFromFile(imgCaminho)){
		std::cerr << "Erro\n";
	}
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(rand() % TAM_JANELA_X, 0.f)); // Spawn em posicao aleatoria
	sprite.setScale(sf::Vector2f(scale_x, scale_y));
}

// _______________________________________________________________________________
void Personagem::iniciarPersInfo(int h, int d)
{
	this->pInfo.iniciarPersInfo(h, d);
}

// _______________________________________________________________________________
void Personagem::iniciarHitbox(float comprimento, float altura, float off_x, float off_y)
{
	/* Inicia o hitbox sendo off_x e off_y o offset x e y da textura para a hitbox */
	this->hitbox.setSprite(&this->sprite);
	this->hitbox.setTamanho(sf::Vector2f(comprimento, altura));
	this->hitbox.setOffsetX(off_x);
	this->hitbox.setOffSetY(off_y);
}

// _______________________________________________________________________________
void Personagem::iniciarCompMov(float vel_max)
{
	this->compMov.iniciarCompMov(&this->sprite, vel_max);
}

// _______________________________________________________________________________

void Personagem::setPosicao(const float x, const float y) { this->sprite.setPosition(x,y); }

sf::FloatRect Personagem::getBounds() const { return this->sprite.getGlobalBounds(); }

sf::Vector2f Personagem::getPosition() const {  return this->sprite.getPosition(); }

HitBox Personagem::getHitbox() const { return this->hitbox; }

PersonagemInfo* Personagem::getPersInfo() { return &this->pInfo; }

ComponenteMovimento* Personagem::getMovComp() { return &this->compMov; }

// _______________________________________________________________________________
void Personagem::receberDano(int dano)
{
	/* Diminui a vida do personagem e atualiza sua barra de vida */
	if (this->invulneravel.getElapsedTime().asMilliseconds() > 400) {
		int vida = this->getPersInfo()->getHp();
		vida = vida - dano;
		this->getPersInfo()->setHP(vida);
		this->barraVida.incrementaValor(-dano);
		this->invulneravel.restart();
	}
}

