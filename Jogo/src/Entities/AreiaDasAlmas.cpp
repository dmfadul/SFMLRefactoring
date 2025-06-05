#include "Core/stdafx.h"
#include "Entities/AreiaDasAlmas.h"

// _______________________________________________________________________________
AreiaDasAlmas::AreiaDasAlmas(const int indice)
	: ObstaculoDanoso(indice, false)
{
}

// _______________________________________________________________________________
AreiaDasAlmas::~AreiaDasAlmas()
{
}

// _______________________________________________________________________________
void AreiaDasAlmas::realizarAcao(Jogador* p)
{
	// Diminui a velocidade do personagem
	p->getMovComp()->setVelY(0);
	p->getMovComp()->setVelX(VELOCIDADE_MAX);
}
