#pragma once
class Gui
{
protected:
	sf::Font fonte;
	sf::Text texto;

public:
	Gui();
	~Gui();

	void iniciarTexto(float pos_x, float pos_y, std::string texto);
	sf::Text* getTexto();

	void desenharGui(sf::RenderTarget& janela);
};

