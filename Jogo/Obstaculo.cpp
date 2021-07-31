#include "stdafx.h"
#include "Obstaculo.h"

// _______________________________________________________________________________
Obstaculo::Obstaculo(const int indice, const bool colidir)
	:Entidade(indice, colidir)
{
	this->dano = 10.f;
	this->iniciarSprite(indice);
}

// _______________________________________________________________________________
Obstaculo::~Obstaculo()
{
}


// _______________________________________________________________________________
void Obstaculo::iniciarSprite(int indice)
{
	/* carrega textura e inicia o sprite */
	std::string s = "./Recursos/Imagens/obstaculos/" + std::to_string(indice) + ".png";

	if (!this->textura.loadFromFile(s)) {
		std::cout << "OBSTACULO::INICIARSPRITE FALHA AO CARREGAR TEXTURA" << std::endl;
		std::cout << s << std::endl;
	}
	this->entidade.setTexture(this->textura);
	this->entidade.setScale(0.25f, 0.25f);
}
