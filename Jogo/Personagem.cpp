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
	try { 
		textura.loadFromFile(imgCaminho);
	}
	catch (...){
		std::cerr << "PERSONAGEM::INICARSPRITE FALHA AO CARREGAR " <<
			imgCaminho << std::endl;
	}

	sprite.setTexture(textura);
	sprite.setPosition(sf::Vector2f((float)(rand() % TAM_JANELA_X), 0.f)); // Spawn em posicao aleatoria
	sprite.setScale(sf::Vector2f(scale_x, scale_y));
}

// _______________________________________________________________________________
void Personagem::iniciarPersInfo(int h, int d)
{
	this->pInfo.iniciarPersInfo(h, d);
}

// _______________________________________________________________________________
void Personagem::iniciarHitbox(float comprimento, float altura, int off_x, int off_y)
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
		this->barraVida -= dano;
		this->invulneravel.restart();
	}
}

// _______________________________________________________________________________
void Personagem::setHp(int hp)
{
	this->getPersInfo()->setHP(hp);
	this->barraVida = hp;
}
