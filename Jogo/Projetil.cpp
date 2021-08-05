#include "stdafx.h"
#include "Projetil.h"


Projetil::Projetil():direcao(true){}

Projetil::Projetil(int indice, sf::Vector2f posicao, bool direcao):direcao(direcao){
	this->iniciarSprite(indice);
	this->setPosicao(posicao.x, posicao.y);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarMovimento();
	this->iniciarCompMov(VEL_MAX_PROJETIL);
	this->compMov.setControleArrasto(false);
}

Projetil::~Projetil(){}

void Projetil::setPosicao(float x, float y)
{
	this->sprite.setPosition(x, y);
}

void Projetil::desenharProjetil(sf::RenderTarget& janela)
{
	janela.draw(this->sprite);
}

void Projetil::iniciarSprite(int indice)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/Projeteis/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "OBSTACULO::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->sprite.setTexture(this->textura);
	this->sprite.setScale(1.f, 1.f);
}

void Projetil::iniciarHitbox(float comprimento, float altura, int off_x, int off_y)
{
	/* Inicia o hitbox sendo off_x e off_y o offset x e y da textura para a hitbox */
	this->hitbox.setSprite(&this->sprite);
	this->hitbox.setTamanho(sf::Vector2f(comprimento, altura));
	this->hitbox.setOffsetX(off_x);
	this->hitbox.setOffSetY(off_y);
}

void Projetil::iniciarCompMov(float vel_max)
{
	this->compMov.iniciarCompMov(&this->sprite, vel_max);
	this->compMov.setCaindo(false);
}

void Projetil::iniciarMovimento()
{
	if (direcao)
		this->compMov.setVelX(-VEL_MAX_PROJETIL);
	else
		this->compMov.setVelX(VEL_MAX_PROJETIL);
}

void Projetil::atualizar()
{
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

int Projetil::getTempoVida()
{
	return tempo_vida.getElapsedTime().asMilliseconds();
}