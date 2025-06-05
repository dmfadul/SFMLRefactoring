#include "stdafx.h"
#include "Botao.h"

// _______________________________________________________________________________
gui::Botao::Botao()
{
	this->ativado = false;
}

// _______________________________________________________________________________
gui::Botao::~Botao()
{
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
void gui::Botao::setCorAtivado(sf::Color ca) { this->corAtivado = ca; }

void gui::Botao::setCorDesativo(sf::Color cd) { this->corDesativado = cd; }

sf::RectangleShape* gui::Botao::getCaixa() { return &this->caixaBotao; }

sf::Text* gui::Botao::getTexto() { return &this->texto; }

// _______________________________________________________________________________
void gui::Botao::desenharBotao(sf::RenderTarget& janela)
{
	/* desenha a caixa do botao e seu texto */
	janela.draw(this->caixaBotao);
	janela.draw(this->texto);
}
