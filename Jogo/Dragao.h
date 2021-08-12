#pragma once
#include "Inimigo.h"
#include "BolaFogo.h"
#include "GeradorProjeteis.h"
#define VIDA_INICIAL_DRAGAO 400
#define DANO_ATAQUE 20
class Dragao :
    public Inimigo
{
private:
	sf::Clock cooldown_atirar;
	GeradorProjeteis* gerProj;
public:
	Dragao();
	Dragao(sf::Vector2f position, GeradorProjeteis* gp);
	~Dragao();

	void desenhar(sf::RenderTarget& janela);
	void atualizar();
	void cuspirFogo();
	
	int getTipo();
};

