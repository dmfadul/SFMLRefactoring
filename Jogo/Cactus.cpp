#include "stdafx.h"
#include "Cactus.h"

Cactus::Cactus(const int indice)
	: Obstaculo(indice, false)
{
}

Cactus::~Cactus()
{
}

void Cactus::realizarAcao(Personagem* p)
{
	/* Cactus causa um dano de 15 */
	p->receberDano(DANO_CACTO);

}

