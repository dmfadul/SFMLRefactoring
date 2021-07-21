#pragma once

/* Classe para entidades */
class Entidade
{
protected:
	sf::Texture textura;
	sf::Sprite entidade;
	bool colidir;

public:
	// construtoras e destrutoras
	Entidade(int indice = 0, const bool colidir = true);
	virtual ~Entidade();

	// metodos
	const bool getColidir() const;
	void setPosicao(const float x, const float y);
	void iniciarSprite(int indice);
	void desenharEntidade(sf::RenderTarget& janela);

};
