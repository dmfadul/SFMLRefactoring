#include "Core/stdafx.h"
#include "UI/Tela.h"

// _______________________________________________________________________________
Tela::Tela()
	: Ente()
{
	this->carregarFonte("../assets/Fontes/Bebas.ttf");
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
		this->fonte.loadFromFile("../assets/Fontes/Bebas.ttf");
	}
	catch (...) {
		std::cerr << "TELA::INICARSPRITE FALHA AO CARREGAR FONTE " << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
