#include "stdafx.h"
#include "Cactus.h"

// _______________________________________________________________________________
Cactus::Cactus(const int indice)
	: ObstaculoDanoso(indice, false)
{
}

// _______________________________________________________________________________
Cactus::~Cactus()
{
}

// _______________________________________________________________________________
void Cactus::realizarAcao(Jogador* p)
{
	/* Cactus causa um dano de 15 */
	p->receberDano(DANO_CACTO);

}

