#pragma once
/* Classe para entidades */
class Entidade
{
protected:
	static int qtdEntidades;
	sf::Texture textura;
	sf::Sprite sprite;
	std::string nome;
	int id;

public:
	// construtoras e destrutoras
	Entidade();
	virtual ~Entidade();

	virtual void atualizar() = 0;
	virtual void desenhar(sf::RenderTarget& janela) = 0;	
	const int getId() const;
	const std::string getNome() const;
};
