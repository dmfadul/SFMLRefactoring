#include "Core/stdafx.h"
#include "Entities/Cowboy.h"

// _______________________________________________________________________________
Cowboy::Cowboy()
	:Jogador()
{
	this->iniciarCowboy();
	this->nome = "COWBOY";
}

// _______________________________________________________________________________
Cowboy::Cowboy(ListaProjeteis* lp, ListaEntidades* le)
	:Jogador(lp, le)
{
	this->iniciarCowboy();
	this->nome = "COWBOY";
}

// _______________________________________________________________________________
Cowboy::~Cowboy()
{
}

// _______________________________________________________________________________
void Cowboy::iniciarCowboy()
{
	this->iniciarSprite("../assets/Imagens/Personagens/cowboy.png", 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL_JOGADOR, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_PLAYER);
	this->barraVida.setTamTexto(22);
	this->barraVida.identificarBarraVida("Cowboy", 10.f, 10.f);
	this->barraVida.setValorMaximo(VIDA_INICIAL_JOGADOR);
}

void Cowboy::mover()
{
	/* Movimenta o jogador de acordo com o Input do usuario */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->compMov.acelerarX(-0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->compMov.acelerarX(0.2f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->compMov.getCaindo() == false)
		this->compMov.setVelY(-13.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && this->cooldown_disparo.getElapsedTime().asMilliseconds() > 350) {
		this->atirar();
		this->cooldown_disparo.restart();
	}
}

// _______________________________________________________________________________
void Cowboy::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
}

// _______________________________________________________________________________
void Cowboy::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	barraVida.desenharBarraVida(janela);
}

