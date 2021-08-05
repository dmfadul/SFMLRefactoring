#pragma once
#include "configuracoes.h"

class ComponenteMovimento
{
private:
	sf::Sprite* sprite;

	// variaveis de movimento
	float gravidade;
	float velMax;
	sf::Vector2f vel;

	// flags
	bool caindo;
	bool controle_arrasto;

public:
	// Construtoras e destrutoras
	ComponenteMovimento();
	~ComponenteMovimento();

	// metodos de inicialicao
	void iniciarCompMov(sf::Sprite* sprite, float vel_max);

	// setters e getters
	void setVelX(float x);
	void setVelY(float y);
	void setCaindo(const bool c);
	void setControleArrasto(const bool a);
	const bool getCaindo() const;
	sf::Vector2f getVelocidade();
	void acelerarX(float x);
	void acelerarY(float y);
	void mover();
	
};

