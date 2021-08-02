#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(JogoInfo* pji)
	: Fase(pji)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/velho_oeste.png");
	this->iniciarMapa("./Recursos/mapas/velho_oeste.txt", 1, 17);
	this->iniciarGerenciadorColisoes();
	this->jogoInfo->getTocaDisco()->tocarFallenDown();
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
	for (auto& personagem : this->personagens)
		personagem->atualizar();

	this->gerColisoes.verificarColisoes();
}

// _______________________________________________________________________________
void VelhoOeste::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Escape){
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->popEnte(); // volta ao menu principal
		}
		if (evento_sfml.key.code == sf::Keyboard::K) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarEnte(new TelaMorte(this->jogoInfo, 100)); // tela de morte
		}
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->background);

	for (auto& personagem : this->personagens)
		personagem->desenhar(janela);

	janela.draw(this->textoScore);

	this->mapa.desenharMapa(janela);
}