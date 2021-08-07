#pragma once
#include "Gui.h"

#define VALOR_MAX_DEFAULT 100
#define TAM_X_DEFAULT 150
#define TAM_Y_DEFAULT 30

class Barra : public Gui
{
private:
	sf::RectangleShape barra;
	sf::RectangleShape contornoBarra;
	sf::Text identBarra;
	int valor;
	int valorMaximo;

public:
	Barra();
	~Barra();

	void iniciarBarra();
	void identificarBarra(std::string ident,float pos_x, float pos_y);
	
	void setTam(float x, float y);
	void setPosicao(float x, float y);
	void setCor(sf::Color c);
	void setTamTexto(int tam);
	void incrementaValor(int v);
	void setValorMaximo(int vm);

	void desenharBarra(sf::RenderTarget& janela);
};

