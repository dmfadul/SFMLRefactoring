#pragma once
#include "Entidade.h"
#include "HitBox.h"

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
	int getHP() const;
	void setHP(int h);

	int getDano() const;
	void setDano(int d);

};

