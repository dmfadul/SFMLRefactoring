#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"
// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji)
	: Fase(pji), mapa(pji, "./Recursos/mapas/ninho_dragao.txt", 101, 12)
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
	janela.draw(this->background);
	this->mapa.desenharMapa(janela);
}
