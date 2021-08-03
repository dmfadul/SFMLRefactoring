#include "stdafx.h"
#include "Espinho.h"

Espinho::Espinho(const int indice)
	:Obstaculo(indice, false)
{
}

Espinho::~Espinho()
{
}

void Espinho::realizarAcao(Jogador* p)
{
	/* Cactus causa um dano de 15 */
	p->receberDano(DANO_ESPINHO);
}
