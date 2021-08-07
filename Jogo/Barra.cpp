#include "stdafx.h"
#include "Barra.h"

Barra::Barra()
{
	this->valor = VALOR_MAX_DEFAULT;
	this->valorMaximo = VALOR_MAX_DEFAULT;
	this->iniciarBarra();
	this->identBarra.setFont(this->fonte);
}

Barra::~Barra()
{
}

void Barra::iniciarBarra()
{
	// inicia a barra
	this->barra.setPosition(40.f, 40.f);
	this->barra.setSize(sf::Vector2f(TAM_X_DEFAULT, TAM_Y_DEFAULT));
	this->barra.setFillColor(sf::Color(0, 120, 0));
	

	this->contornoBarra.setPosition(40.f, 40.f);
	this->contornoBarra.setFillColor(sf::Color::Transparent);
	this->contornoBarra.setOutlineColor(sf::Color::Black);
	this->contornoBarra.setSize(sf::Vector2f(TAM_X_DEFAULT, TAM_Y_DEFAULT));
	this->contornoBarra.setOutlineThickness(1.f);

	// inicia o texto da barra
	std::string texto_barra = std::to_string(valor) + " / " + std::to_string(valorMaximo);
	this->iniciarTexto(100.f, 100.f, texto_barra);
	this->texto.setPosition(
		this->barra.getPosition().x + 15.f,
		this->barra.getPosition().y + this->barra.getGlobalBounds().height / 2 - this->texto.getGlobalBounds().height / 2
	);
}

//
void Barra::identificarBarra(std::string ident, float pos_x, float pos_y)
{
	this->identBarra.setString(ident);
	this->identBarra.setCharacterSize(22);
	this->identBarra.setPosition(pos_x, pos_y);
}

void Barra::setTam(float x, float y)
{
	this->barra.setSize(sf::Vector2f(x, y));
	this->contornoBarra.setSize(sf::Vector2f(x, y));
}

void Barra::setPosicao(float x, float y)
{
	this->barra.setPosition(x, y);
	this->contornoBarra.setPosition(x, y);
	this->texto.setPosition(
		x + 15.f,
		y + 3.f
	);

}

void Barra::setCor(sf::Color c)
{
	this->barra.setFillColor(c);
}

void Barra::setTamTexto(int tam)
{
	this->texto.setCharacterSize(tam);
}

void Barra::incrementaValor(int v)
{
	// incrementa o valor e o tamanho da barra
	this->valor += v;
	std::string texto_barra;
	if (valor >= 0) {
		int tam_barra = (int)(this->valor / (this->valorMaximo * 1.f) * (int)(this->contornoBarra.getGlobalBounds().width));
		this->barra.setSize(sf::Vector2f((float)(tam_barra), this->contornoBarra.getGlobalBounds().height));
		texto_barra = std::to_string(valor) + " / " + std::to_string(valorMaximo);
	}
	else
	{
		this->barra.setSize(sf::Vector2f(0, 0));
		texto_barra = "0 / " + std::to_string(valorMaximo);
	}
	this->texto.setString(texto_barra);
}

void Barra::setValorMaximo(int vm)
{
	this->valorMaximo = vm;
	this->valor = vm;
}

void Barra::desenharBarra(sf::RenderTarget& janela)
{
	janela.draw(barra);
	janela.draw(identBarra);
	janela.draw(texto);
	janela.draw(contornoBarra);
}
