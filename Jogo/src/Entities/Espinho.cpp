#include "Core/stdafx.h"
#include "Entities/Espinho.h"

// _______________________________________________________________________________
Espinho::Espinho(const int indice)
	:ObstaculoDanoso(indice, false)
{
}

// _______________________________________________________________________________
Espinho::~Espinho()
{
}

// _______________________________________________________________________________
void Espinho::realizarAcao(Jogador* p)
{
	/* Cactus causa um dano de 15 */
	p->receberDano(DANO_ESPINHO);
}
