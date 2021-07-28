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

	// getters e setters
	const bool getColidir() const;
	void setPosicao(const float x, const float y);

	// metodos
	virtual void iniciarSprite(int indice) = 0;
	void desenharEntidade(sf::RenderTarget& janela);

};
