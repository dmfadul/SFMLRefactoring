#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste()
{
}

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(EnteInfo* pei)
	: Fase(pei)
{
	this->iniciarBackground("./Recursos/Imagens/velho_oeste.png");
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
}

// _______________________________________________________________________________
void VelhoOeste::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape)
			this->enteInfo->entes->pop(); // volta ao menu principal
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderWindow& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->background);
}
