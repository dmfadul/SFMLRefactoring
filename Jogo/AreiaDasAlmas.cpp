#include "stdafx.h"
#include "AreiaDasAlmas.h"

AreiaDasAlmas::AreiaDasAlmas(const int indice)
	: Obstaculo(indice, false)
{
}

AreiaDasAlmas::~AreiaDasAlmas()
{
}

void AreiaDasAlmas::realizarAcao(Personagem* p)
{
	// Diminui a velocidade do personagem
	p->getMovComp()->setVelY(0);
	p->getMovComp()->setVelX(VELOCIDADE_MAX);
}
