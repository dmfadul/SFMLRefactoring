#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"
// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji)
	: Fase(pji), mapa("./Recursos/mapas/ninho_dragao.txt", 101, 12), cowboy("./Recursos/Imagens/Personagens/Cowboy/tile000.png"), cowboy2("./Recursos/Imagens/Personagens/Cowboy/tile000.png")
{
	this->iniciarBackground("./Recursos/Imagens/backgrounds/ninho_do_dragao.png");
	this->jogoInfo->getTocaDisco()->tocarSpearOfJustice();
}

// _______________________________________________________________________________
NinhoDoDragao::~NinhoDoDragao()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizar()
{
	cowboy.atualizar();
	cowboy2.atualizar();
	cowboy.verificarColisao(cowboy2.getPosition(), cowboy2.getSize(), 1.0);
	cowboy.atualizar();
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->popEnte(); // volta ao menu principal
		}
	}
}

// _______________________________________________________________________________
void NinhoDoDragao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.clear();
	janela.draw(this->background);
	cowboy.desenhar(janela);
	this->mapa.desenharMapa(janela);
	
}
