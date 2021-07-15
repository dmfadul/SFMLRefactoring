#include "stdafx.h"
#include "Botao.h"

// _______________________________________________________________________________
gui::Botao::Botao()
{
	this->ativado = false;
}

// _______________________________________________________________________________
gui::Botao::Botao(float pos_x, float pos_y, std::string texto)
{
	// Inicia Botão
	this->iniciarBotao(pos_x, pos_y, texto);
}

// _______________________________________________________________________________
gui::Botao::~Botao()
{
}

// _______________________________________________________________________________
void gui::Botao::iniciarBotao(float pos_x, float pos_y, std::string texto)
{
	this->ativado = false;
	this->corAtivado = sf::Color::White;
	this->corDesativado = sf::Color(150, 150, 150);

	this->iniciarCaixa(pos_x, pos_y);
	this->iniciarTexto(pos_x, pos_y, texto);
}

// _______________________________________________________________________________
void gui::Botao::iniciarCaixa(float pos_x, float pos_y)
{
	/* Inicia a caixa do botão */
	this->caixaBotao.setFillColor(sf::Color::Transparent);
	this->caixaBotao.setPosition(pos_x, pos_y);
	this->caixaBotao.setSize(sf::Vector2f(200.f, 50.f));
}

// _______________________________________________________________________________
void gui::Botao::iniciarTexto(float pos_x, float pos_y, std::string texto)
{
	/* Inicia fonte e centraliza o texto no botão */
	if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")){
		std::cout << "BOTAO::FALHA AO CARREGAR FONTE" << std::endl;
	}

	// Inicia texto
	this->texto.setString(texto);
	this->texto.setFont(this->fonte);
	this->texto.setFillColor(this->corDesativado);
	this->texto.setCharacterSize(38);

	// centraliza o texto no botao
	this->texto.setPosition(
		pos_x + this->caixaBotao.getGlobalBounds().width / 2 - this->texto.getGlobalBounds().width / 2,
		pos_y + this->caixaBotao.getGlobalBounds().height / 2 - this->texto.getGlobalBounds().height / 2 - this->texto.getCharacterSize() / 4);

}

// _______________________________________________________________________________
void gui::Botao::ativar()
{
	this->texto.setFillColor(this->corAtivado);
	this->ativado = true;
}

// _______________________________________________________________________________
void gui::Botao::desativar()
{
	this->texto.setFillColor(this->corDesativado);
	this->ativado = false;
}

// _______________________________________________________________________________
void gui::Botao::setCorAtivado(sf::Color ca)
{
	this->corAtivado = ca;
}

// _______________________________________________________________________________
void gui::Botao::desenharBotao(sf::RenderTarget& janela)
{
	/* desenha a caixa do botao e seu texto */
	janela.draw(this->caixaBotao);
	janela.draw(this->texto);
}
