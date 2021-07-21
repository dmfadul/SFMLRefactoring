#include "stdafx.h"
#include "Entidade.h"

// _______________________________________________________________________________
Entidade::Entidade(int indice,const bool colidir)
{
	this->colidir = colidir;
	this->iniciarSprite(indice);
}

// _______________________________________________________________________________
Entidade::~Entidade()
{
}


// _______________________________________________________________________________
const bool Entidade::getColidir() const
{
	return this->colidir;
}

// _______________________________________________________________________________
void Entidade::setPosicao(const float x, const float y)
{
	this->entidade.setPosition(x, y);
}


// _______________________________________________________________________________
void Entidade::iniciarSprite(int indice)
{
	std::string s = "./Recursos/Imagens/" + std::to_string(indice) + ".png";

	this->colidir = true;
	if (!this->textura.loadFromFile(s)) {
		std::cout << "ENTE::FALHA AO CARREGAR BACKGROUND" << std::endl;
	}
	this->entidade.setTexture(this->textura);
	this->entidade.setScale(0.25f, 0.25f);
}

// _______________________________________________________________________________
void Entidade::desenharEntidade(sf::RenderTarget& janela)
{
	janela.draw(this->entidade);
}
