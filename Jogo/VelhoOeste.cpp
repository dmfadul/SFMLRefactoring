#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste() :
	mapa(this->jogoInfo, "./Recursos/src/velho_oeste.txt")
{
}

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(JogoInfo* pji)
	: Fase(pji), mapa(this->jogoInfo, "./Recursos/src/velho_oeste.txt")
{
	this->iniciarBackground("./Recursos/Imagens/velho_oeste.png");
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
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
		if (evento_sfml.key.code == sf::Keyboard::Escape){
			this->jogoInfo->setEncerrarEnte(true); // volta ao menu principal
		}
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->background);
	this->mapa.desenharMapa(janela);
}