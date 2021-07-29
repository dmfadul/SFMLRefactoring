#pragma once
#include "Entidade.h"
<<<<<<<<< Temporary merge branch 1
class Personagem 
{
=========
class Personagem {

protected:

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

