#include "stdafx.h"
#include "Obstaculo.h"

// _______________________________________________________________________________
Obstaculo::Obstaculo(const int indice, const bool colidir)
	: Bloco(colidir)
{
	this->dano = 10.f;
	this->iniciarSprite(indice, 0.25f, 0.25f);
}

// _______________________________________________________________________________
Obstaculo::~Obstaculo()
{
}

// _______________________________________________________________________________
void Obstaculo::iniciarSprite(int indice, float scale_x, float scale_y)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/obstaculos/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "OBSTACULO::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->sprite.setTexture(this->textura);
	this->sprite.setScale(scale_x, scale_y);
}
