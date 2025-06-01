#include "stdafx.h"
#include "Bruxa.h"

// _______________________________________________________________________________
Bruxa::Bruxa(): tempo_direcao(1000), gerProj(NULL), tempo_cooldown(500) {}

// _______________________________________________________________________________
Bruxa::Bruxa(sf::Vector2f position, GeradorProjeteis* gp, int tempo_direcao):
	tempo_direcao(tempo_direcao),gerProj(gp)
{
	vivo = true;
	this->tempo_cooldown = rand() % 1000 + 500;
	this->recompensa = 20;
	this->iniciarSprite("./Recursos/Imagens/Personagens/bruxa.png", 2.f, 2.f);
	this->iniciarPersInfo(VIDA_INICIAL, DANO_ATAQUE);
	this->iniciarHitbox(25.f, 36.f, 15, 25);
	this->iniciarCompMov(VEL_MAX_BRUXA);
	this->sprite.setPosition(position);
	this->compMov.setControleArrasto(false);
	start();
	//detach();
	this->barraVida.setValorMaximo(VIDA_INICIAL);
	this->nome = "BRUXA";
	
}

// _______________________________________________________________________________
void Bruxa::run()
{
	int id = getId();
	
	std::cout << "Thread running " << std::endl;
	while (vivo && getId()==id)
	{
		
		atirar();
		// Sleep(4);
	}
}
// _______________________________________________________________________________
Bruxa::~Bruxa()
{
	//this->gerProj = 0;
	vivo = false;
}

// _______________________________________________________________________________
void Bruxa::mover()
{
	if (this->tempo_vida.getElapsedTime().asMilliseconds() > tempo_direcao) {
		direction = !direction;
		tempo_vida.restart();
	}

	if (direction)
		this->compMov.setVelX(-VEL_MAX_BRUXA);
	else
		this->compMov.setVelX(VEL_MAX_BRUXA);
	
}

// _______________________________________________________________________________
void Bruxa::atualizar()
{
	this->mover();
	this->compMov.mover();
	this->hitbox.atualizarPosicao();
	this->barraVida.setPosicao(this->sprite.getPosition().x + 10.f, this->sprite.getPosition().y);
	
}

// _______________________________________________________________________________
void Bruxa::atirar()
{
	if (this->getPersInfo()->getHp() > 0) {
		if (this->cooldown_projetil.getElapsedTime().asMilliseconds() > 1500) {
			this->cooldown_projetil.restart();
			//this->tempo_cooldown = rand() % 1000 + 500;
			this->gerProj->CriarProjetil(new Morcego(this->getHitbox().getCima(), this->direction));
		}
	}
}

// _______________________________________________________________________________
void Bruxa::desenhar(sf::RenderTarget& janela)
{
	janela.draw(sprite);
	barraVida.desenharBarraVida(janela);
}
