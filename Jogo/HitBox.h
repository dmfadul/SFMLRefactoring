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
	const sf::Vector2f getEsquerda() const;
	const sf::Vector2f getDireita() const;
	const sf::Vector2f getCima() const;
	const sf::Vector2f getCimaEsquerda() const;
	const sf::Vector2f getCimaDireita() const;
	const sf::Vector2f getBaixoEsquerda() const;
	const sf::Vector2f getBaixoDireita() const;
	const sf::FloatRect getBounds() const;
	const float getWidth() const;
	const float getHeight() const;
	const int getOffsetX() const;
	const int getOffsetY() const;

	void atualizarPosicao();
	void desenhar(sf::RenderTarget& janela);
};

