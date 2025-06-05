#pragma once
#include "Gui.h"

#define VALOR_MAX_DEFAULT 100
#define TAM_X_DEFAULT 150
#define TAM_Y_DEFAULT 30

/* Classe da barra vida dos personagens */
namespace gui 
{
	class BarraVida : public Gui
	{
	private:
		// variaveis
		sf::RectangleShape barra;
		sf::RectangleShape contornoBarraVida;
		sf::Text identBarraVida;
		int valor;
		int valorMaximo;

	public:
		// construtoras e destrutoras
		BarraVida();
		~BarraVida();

		// metodos 
		void iniciarBarraVida();
		void identificarBarraVida(std::string ident, float pos_x, float pos_y);
		void desenharBarraVida(sf::RenderTarget& janela);

		// setters e getters
		void setTam(float x, float y);
		void setPosicao(float x, float y);
		void setCor(sf::Color c);
		void setTamTexto(int tam);
		void incrementaValor(int v);
		void setValor(int v);
		void setValorMaximo(int vm);

		// sobrecarga de operadores
		void operator-=(const int v);
		void operator+=(const int v);
		void operator=(const int v);

	};
}

