#include "Core/stdafx.h"
#include "Entities/BarraVida.h"

// _______________________________________________________________________________
gui::BarraVida::BarraVida()
{
	this->valor = VALOR_MAX_DEFAULT;
	this->valorMaximo = VALOR_MAX_DEFAULT;
	this->iniciarBarraVida();
	this->identBarraVida.setFont(this->fonte);
}

// _______________________________________________________________________________
gui::BarraVida::~BarraVida()
{
}

// _______________________________________________________________________________
void gui::BarraVida::iniciarBarraVida()
{
	// inicia a barra
	this->barra.setPosition(40.f, 40.f);
	this->barra.setSize(sf::Vector2f(TAM_X_DEFAULT, TAM_Y_DEFAULT));
	this->barra.setFillColor(sf::Color(0, 120, 0));
	

	this->contornoBarraVida.setPosition(40.f, 40.f);
	this->contornoBarraVida.setFillColor(sf::Color::Transparent);
	this->contornoBarraVida.setOutlineColor(sf::Color::Black);
	this->contornoBarraVida.setSize(sf::Vector2f(TAM_X_DEFAULT, TAM_Y_DEFAULT));
	this->contornoBarraVida.setOutlineThickness(1.f);

	// inicia o texto da barra
	std::string texto_barra = std::to_string(valor) + " / " + std::to_string(valorMaximo);
	this->iniciarTexto(100.f, 100.f, texto_barra);
	this->texto.setPosition(
		this->barra.getPosition().x + 15.f,
		this->barra.getPosition().y + this->barra.getGlobalBounds().height / 2 - this->texto.getGlobalBounds().height / 2
	);
}

// _______________________________________________________________________________
void gui::BarraVida::identificarBarraVida(std::string ident, float pos_x, float pos_y)
{
	this->identBarraVida.setString(ident);
	this->identBarraVida.setCharacterSize(22);
	this->identBarraVida.setPosition(pos_x, pos_y);
}

// _______________________________________________________________________________
void gui::BarraVida::setTam(float x, float y)
{
	this->barra.setSize(sf::Vector2f(x, y));
	this->contornoBarraVida.setSize(sf::Vector2f(x, y));
}

// _______________________________________________________________________________
void gui::BarraVida::setPosicao(float x, float y)
{
	this->barra.setPosition(x, y);
	this->contornoBarraVida.setPosition(x, y);
	this->texto.setPosition(
		x + 15.f,
		y + 3.f
	);

}

// _______________________________________________________________________________
void gui::BarraVida::setCor(sf::Color c)
{
	this->barra.setFillColor(c);
}

// _______________________________________________________________________________
void gui::BarraVida::setTamTexto(int tam)
{
	this->texto.setCharacterSize(tam);
}

// _______________________________________________________________________________
void gui::BarraVida::incrementaValor(int v)
{
	// incrementa o valor e o tamanho da barra
	this->valor += v;
	std::string texto_barra;
	if (valor >= 0) {
		int tam_barra = (int)(this->valor / (this->valorMaximo * 1.f) * (int)(this->contornoBarraVida.getGlobalBounds().width));
		this->barra.setSize(sf::Vector2f((float)(tam_barra), this->contornoBarraVida.getGlobalBounds().height));
		texto_barra = std::to_string(valor) + " / " + std::to_string(valorMaximo);
	}
	else
	{
		this->barra.setSize(sf::Vector2f(0, 0));
		texto_barra = "0 / " + std::to_string(valorMaximo);
	}
	this->texto.setString(texto_barra);
}

// _______________________________________________________________________________
void gui::BarraVida::setValor(int v)
{
	// define o valor e o tamanho da barra
	this->valor = v;
	std::string texto_barra;
	if (valor >= 0) {
		int tam_barra = (int)(this->valor / (this->valorMaximo * 1.f) * (int)(this->contornoBarraVida.getGlobalBounds().width));
		this->barra.setSize(sf::Vector2f((float)(tam_barra), this->contornoBarraVida.getGlobalBounds().height));
		texto_barra = std::to_string(valor) + " / " + std::to_string(valorMaximo);
	}
	else
	{
		this->barra.setSize(sf::Vector2f(0, 0));
		texto_barra = "0 / " + std::to_string(valorMaximo);
	}
	this->texto.setString(texto_barra);
}

// _______________________________________________________________________________
void gui::BarraVida::setValorMaximo(int vm)
{
	this->valorMaximo = vm;
	this->valor = vm;
	this->incrementaValor(0);
}

// _______________________________________________________________________________
void gui::BarraVida::desenharBarraVida(sf::RenderTarget& janela)
{
	janela.draw(barra);
	janela.draw(identBarraVida);
	janela.draw(texto);
	janela.draw(contornoBarraVida);
}

// _______________________________________________________________________________
void gui::BarraVida::operator-=(const int v)
{
	this->incrementaValor(-v);
}

// _______________________________________________________________________________
void gui::BarraVida::operator+=(const int v)
{
	this->incrementaValor(v);
}

// _______________________________________________________________________________
void gui::BarraVida::operator=(const int v)
{
	this->setValor(v);
}
