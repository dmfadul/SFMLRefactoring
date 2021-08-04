#pragma once
/* Classe para entidades */
class Entidade
{
protected:
	static int qtdEntidades;
	sf::Texture textura;
	sf::Sprite sprite;
	int id;

public:
	// construtoras e destrutoras
	Entidade();
	virtual ~Entidade();

	const int getId() const;
};
