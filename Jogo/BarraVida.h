#pragma once
#include "Gui.h"

#define VALOR_MAX_DEFAULT 100
#define TAM_X_DEFAULT 150
#define TAM_Y_DEFAULT 30

class BarraVida : public Gui
{
private:
	sf::RectangleShape barra;
	sf::RectangleShape contornoBarraVida;
	sf::Text identBarraVida;
	int valor;
	int valorMaximo;

public:
	BarraVida();
	~BarraVida();

	void iniciarBarraVida();
	void identificarBarraVida(std::string ident,float pos_x, float pos_y);
	
	void setTam(float x, float y);
	void setPosicao(float x, float y);
	void setCor(sf::Color c);
	void setTamTexto(int tam);
	void incrementaValor(int v);
	void setValorMaximo(int vm);

	void desenharBarraVida(sf::RenderTarget& janela);
	
	void operator-=(const int v);
	void operator+=(const int v);

};

