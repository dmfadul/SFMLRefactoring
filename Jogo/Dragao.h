#pragma once
#include "Inimigo.h"
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20
class Dragao :
    public Inimigo
{

private:
	sf::Clock tempo_vida;
public:
	Dragao();
	Dragao(sf::Vector2f position);
	~Dragao();

	void desenhar(sf::RenderTarget& janela);
	void atualizar();
	
	int getTipo();
};

