#include "stdafx.h"
#include "BuilderBotao.h"

// _______________________________________________________________________________
BuilderBotao::BuilderBotao()
{
	this->botao = 0;
}

// _______________________________________________________________________________
BuilderBotao::~BuilderBotao()
{
	this->botao = 0;
}

// _______________________________________________________________________________
void BuilderBotao::buildTexto(int tam_char, std::string fontDir, std::string texto)
{
	/* Inicia fonte e centraliza o texto no bot�o */
	try { 
		this->fonte.loadFromFile(fontDir);
	} catch(...){
		std::cerr << "BUILDERBOTAO::FALHA AO CARREGAR FONTE" << std::endl;
	}

	// Inicia texto
	sf::Text* text = this->botao->getTexto();
	text->setString(texto);
	text->setFont(this->fonte);
	text->setCharacterSize(tam_char);
}

// _______________________________________________________________________________
void BuilderBotao::buildCaixa(float pos_x, float pos_y, sf::Vector2f tam)
{
	// posicao e tamanho da caixa
	sf::RectangleShape* caixa = this->botao->getCaixa();
	caixa->setPosition(pos_x, pos_y);
	caixa->setSize(tam);

	// centraliza o texto no botao
	sf::Text* texto = this->botao->getTexto();
	texto->setPosition(
		pos_x + caixa->getGlobalBounds().width / 2 - texto->getGlobalBounds().width / 2,
		pos_y + caixa->getGlobalBounds().height / 2 - texto->getGlobalBounds().height / 2 - texto->getCharacterSize() / 4
	);
}

// _______________________________________________________________________________
void BuilderBotao::buildCores(sf::Color ativado, sf::Color desativado, sf::Color cor_caixa)
{
	this->botao->setCorAtivado(ativado);
	this->botao->setCorDesativo(desativado);
	this->botao->getCaixa()->setFillColor(cor_caixa);
	this->botao->getTexto()->setFillColor(desativado);
}
