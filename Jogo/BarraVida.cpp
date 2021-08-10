#include "stdafx.h"
#include "BarraVida.h"

BarraVida::BarraVida()
{
	this->valor = VALOR_MAX_DEFAULT;
	this->valorMaximo = VALOR_MAX_DEFAULT;
	this->iniciarBarraVida();
	this->identBarraVida.setFont(this->fonte);
}

BarraVida::~BarraVida()
{
}

void BarraVida::iniciarBarraVida()
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

//
void BarraVida::identificarBarraVida(std::string ident, float pos_x, float pos_y)
{
	this->identBarraVida.setString(ident);
	this->identBarraVida.setCharacterSize(22);
	this->identBarraVida.setPosition(pos_x, pos_y);
}

void BarraVida::setTam(float x, float y)
{
	this->barra.setSize(sf::Vector2f(x, y));
	this->contornoBarraVida.setSize(sf::Vector2f(x, y));
}

void BarraVida::setPosicao(float x, float y)
{
	this->barra.setPosition(x, y);
	this->contornoBarraVida.setPosition(x, y);
	this->texto.setPosition(
		x + 15.f,
		y + 3.f
	);

}

void BarraVida::setCor(sf::Color c)
{
	this->barra.setFillColor(c);
}

void BarraVida::setTamTexto(int tam)
{
	this->texto.setCharacterSize(tam);
}

void BarraVida::incrementaValor(int v)
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

void BarraVida::setValorMaximo(int vm)
{
	this->valorMaximo = vm;
	this->valor = vm;
	this->incrementaValor(0);
}

void BarraVida::desenharBarraVida(sf::RenderTarget& janela)
{
	janela.draw(barra);
	janela.draw(identBarraVida);
	janela.draw(texto);
	janela.draw(contornoBarraVida);
}

void BarraVida::operator-=(const int v)
{
	this->incrementaValor(-v);
}

void BarraVida::operator+=(const int v)
{
	this->incrementaValor(v);
}
