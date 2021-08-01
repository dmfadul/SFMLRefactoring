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
	
	// Getters
	const int getId() const;
	const int getHP() const;
	const int getDano() const;
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;

	// get components
	HitBox getHitbox() const;
	ComponenteMovimento* getMovComp();

	// metodos
	virtual void atualizar() = 0;
	virtual void desenhar(sf::RenderTarget& janela) = 0;

};

