#include "stdafx.h"
#include "Tela.h"

// _______________________________________________________________________________
Tela::Tela()
	: Ente()
{
	this->carregarFonte("./Recursos/Fontes/Bebas.ttf");
}

// _______________________________________________________________________________
Tela::~Tela()
{
}

// _______________________________________________________________________________
void Tela::carregarFonte(std::string diretorio)
{
	/* carrega a fonte */
	try {
		this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf");
	}
	catch (...) {
		std::cerr << "TELA::INICARSPRITE FALHA AO CARREGAR FONTE " << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
