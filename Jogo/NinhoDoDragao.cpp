#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji)
	: Fase(pji)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/ninho_do_dragao.png");
	this->iniciarMapa("./Recursos/mapas/ninho_dragao.txt", 101, 17, 2);
	this->iniciarGerenciadorColisoes();
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
	for (auto& personagem : this->personagens)
		personagem->atualizar();

	this->gerColisoes.verificarColisoes();
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
	
	for (auto& personagem : this->personagens)
		personagem->desenhar(janela);

	janela.draw(this->textoScore);
	this->mapa.desenharMapa(janela);
	
}
