#pragma once
#include "Entidade.h"
#include "HitBox.h"
#include "ComponenteMovimento.h"
#include "PersonagemInfo.h"

/* Classe Abstrata de Personagem */
class Personagem {

protected:
	sf::Texture texture;
	sf::Sprite sprite;

	// Components
	HitBox hitbox;
	PersonagemInfo pInfo;
	ComponenteMovimento compMov;

public:

	// Construtora e Destrutora
	Personagem();
	~Personagem();

	// metodos de inicializacao
	void iniciarSprite(std::string imgCaminho, float scale_x, float scale_y);
	void iniciarPersInfo(int h, int d);
	void iniciarHitbox(float comprimento, float altura, float off_x, float off_y);
	void iniciarCompMov(float vel_max);

	// Setters
	void setPosicao(const float x, const float y);
	
	// Getters
	sf::FloatRect getBounds() const;
	sf::Vector2f getPosition() const;

	// get components
	HitBox getHitbox() const;
	PersonagemInfo* getPersInfo();
	ComponenteMovimento* getMovComp();

	// metodos
	virtual void atualizar() = 0;
	virtual void desenhar(sf::RenderTarget& janela) = 0;

};

