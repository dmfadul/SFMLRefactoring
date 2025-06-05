#pragma once
#include "Entities/Entidade.h"
#include "Utils/HitBox.h"
#include "Core/ComponenteMovimento.h"
#include "Utils/PersonagemInfo.h"
#include "Entities/BarraVida.h"
#include "Entities/Entidade.h"

/* Classe Abstrata de Personagem */
class Personagem : public Entidade{

protected:
	sf::Clock invulneravel;

	// Components
	gui::BarraVida barraVida;
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
	void iniciarHitbox(float comprimento, float altura, int off_x, int off_y);
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
	virtual void receberDano(int dano);
	void setHp(int hp);
};

