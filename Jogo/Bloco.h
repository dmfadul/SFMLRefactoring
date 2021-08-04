#pragma once
#include "Entidade.h"
class Bloco :
    public Entidade
{
private:
    bool colidir;

public:
	// Construtoras e Destrutoras
	Bloco(const bool colidir = true);
	~Bloco();

	// getters e setters
	const bool getColidir();
	void setPosicao(const float x, const float y);
	const int getId(int id);

	void desenharBloco(sf::RenderTarget& janela);
};

