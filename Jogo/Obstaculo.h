#pragma once
#include "Entidade.h"

class Obstaculo :
    public Entidade
{
private:
    bool colidir;

public:
	// Construtoras e Destrutoras
	Obstaculo(const bool colidir = true);
	~Obstaculo();

	// getters e setters
	const bool getColidir();
	void setPosicao(const float x, const float y);

	void atualizar();
	void desenhar(sf::RenderTarget& janela);
};

