#pragma once
#include "Entidade.h"
#include "HitBox.h"
#include "ComponenteMovimento.h"

/* Classe Abstrata de Personagem */
class Personagem {

protected:
	static int qtdPersonagens;
	sf::Texture texture;
	sf::Sprite sprite;
	int id, hp, dano;

	// Components
	HitBox hitbox;
	ComponenteMovimento compMov;

public:

	// Construtora e Destrutora
	Personagem();
	~Personagem();

	// Setters
	void setHP(int h);
	void setDano(int d);
	void setPosicao(const float x, const float y);
	void setVelX(const float x);
	void setVelY(const float y);
	void setCaindo(const bool c);
	
	// Getters
	const int getId() const;
	const int getHP() const;
	const int getDano() const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;
	HitBox getHitbox() const;

	// metodos
	virtual void atualizar() = 0;
	virtual void desenhar(sf::RenderTarget& janela) = 0;

};

