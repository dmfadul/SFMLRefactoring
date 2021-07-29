#pragma once
#include "Entidade.h"
#include "HitBox.h"

/* Classe Abstrata de Personagem */
class Personagem {

protected:
	sf::Texture texture;
	sf::Sprite sprite;
	HitBox hitbox;
	int hp;
	int dano;

public:

	//Construtora e Destrutora
	Personagem();
	~Personagem();

	//Funcoes
	void setHP(int h);
	void setDano(int d);

	const int getHP() const;
	const int getDano() const;

};

