#include "stdafx.h"
#include "Cobra.h"

// _______________________________________________________________________________
Cobra::Cobra()
{
	this->cooldown_pulo = 0;
	this->jogadores = NULL;
}

// _______________________________________________________________________________
Cobra::Cobra(ListaJogadores* jogadores, sf::Vector2f position)
{
	this->recompensa = 15;
	this->jogadores = jogadores;
	this->iniciarSprite("./Recursos/Imagens/Personagens/cobra.png", 2.f, 2.f);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->iniciarPersInfo(VIDA_INICIAL_COBRA, DANO_COBRA);
	this->iniciarHitbox(28.f, 26.f, 10, 37);
	this->iniciarCompMov(VEL_MAX_COBRA);
	this->cooldown_pulo = rand() % MAX_COOLDOWN_PULO;
	this->barraVida.setValorMaximo(VIDA_INICIAL_COBRA);
	this->nome = "COBRA";
}

// _______________________________________________________________________________
Cobra::~Cobra()
{
	this->jogadores = NULL;
}

// _______________________________________________________________________________
void Cobra::mover()
{	
	/* Persegue o primeiro jogador na lista */
	if (this->jogadores->listaVazia() == false) {
		Lista<Jogador>::Elemento<Jogador>* pElJogador = this->jogadores->getPrimeiro();
		Jogador* pJogador = pElJogador->getInfo();

		if (pJogador->getHitbox().getCima().x > this->getHitbox().getCima().x + 10.f)
			this->compMov.acelerarX(0.2f);
		else if (pJogador->getHitbox().getCima().x < this->getHitbox().getCima().x - 10.f)
			this->compMov.acelerarX(-0.2f);
	}

	// pula apos cooldown aleatorio
	if (this->timer_pulo.getElapsedTime().asMilliseconds() > this->cooldown_pulo && this->compMov.getCaindo() == false) {
		this->compMov.setVelY(-13.f);
		this->timer_pulo.restart();
		this->cooldown_pulo = rand() % MAX_COOLDOWN_PULO;
	}
}

// _______________________________________________________________________________
void Cobra::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
	this->barraVida.setPosicao(this->sprite.getPosition().x + 10.f, this->sprite.getPosition().y + 10.f);
}

// _______________________________________________________________________________
void Cobra::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	barraVida.desenharBarraVida(janela);
}
