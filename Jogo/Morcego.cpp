#include "stdafx.h"
#include "Morcego.h"

Morcego::Morcego(){}

Morcego::Morcego(int indice, sf::Vector2f posicao)
{
	this->iniciarSprite(indice);
	this->setPosicao(posicao.x,posicao.y);
}

Morcego::~Morcego(){}

void Morcego::iniciarSprite(int indice)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/Projeteis/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "OBSTACULO::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->entidade.setTexture(this->textura);
	this->entidade.setScale(1.f, 1.f);
}