#pragma once
class HitBox
{
private:
	sf::RectangleShape hitbox;
	sf::Sprite* sprite;
	int offsetX;
	int offsetY;

public:
	// Construtoras e destrutoras
	HitBox(sf::Sprite* s = NULL);
	~HitBox();

	// setters e getters
	void setSprite(sf::Sprite* s);
	void setTamanho(const sf::Vector2f tam);
	void setOffsetX(const int o);
	void setOffSetY(const int o);
	sf::FloatRect getBounds();

	// limites do hitbox
	const sf::Vector2f getEsquerda() const;
	const sf::Vector2f getDireita() const;
	const sf::Vector2f getCima() const;
	const sf::Vector2f getBaixoEsquerda() const;
	const sf::Vector2f getBaixoDireita() const;

	// offsets do hitbox com o sprite
	const int getOffsetCima() const;
	const int getOffsetBaixo() const;
	const int getOffsetEsquerda() const;
	const int getOffsetDireira() const;

	// metodos
	void atualizarPosicao();
	void desenhar(sf::RenderTarget& janela);
};

