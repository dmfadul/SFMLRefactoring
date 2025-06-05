#pragma once
class Gui
{
protected:
	// variaveis
	sf::Font fonte;
	sf::Text texto;

public:
	// construtoras e destrutoras
	Gui();
	~Gui();

	// setters e getters
	void setTexto(std::string texto);
	sf::Text* getTexto();

	// metodos
	void iniciarTexto(float pos_x, float pos_y, std::string texto);
	void desenharGui(sf::RenderTarget& janela);
};

