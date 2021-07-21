#include "stdafx.h"
#include "Mapa.h"

// _______________________________________________________________________________
Mapa::Mapa(JogoInfo* pji, std::string diretorio)
	:jogoinfo(pji)
{

	this->tamMapaX = pji->getTamMapaX();
	this->tamMapaY = pji->getTamMapaY();
	this->tamEntidade = pji->getTamEntidade();

	this->carregarMapa(diretorio);
	this->iniciarEntidades();
}

// _______________________________________________________________________________
Mapa::~Mapa()
{
	// desaloca mapa
	for (int y = 0; y < this->tamMapaY; y++) {
		for (int x = 0; x < this->tamMapaX; x++) {
			this->mapa[x][y] = NULL;
		}
	}

	// desaloca entidades
	for (auto& ent : this->entidades) {
		delete ent;
	}
} 

// _______________________________________________________________________________
void Mapa::carregarMapa(std::string diretorio)
{
	/* le o mapa apartir de um arquivo */
	this->mapa.resize(tamMapaX);
	for (int i = 0; i < tamMapaX; i++)
		this->mapa[i].resize(tamMapaY);

	// abre o arquivo com o mapa
	std::fstream arquivo_mapa;
	arquivo_mapa.open(diretorio, std::ios::in);
	int n = 0;

	// salva o mapa na matriz mapa
	for (int y = 0; y < tamMapaY; y++) {
		for (int x = 0; x < tamMapaX; x++) {
			if (arquivo_mapa >> n)
				this->mapa[x][y] = n;
		}
	}

	// fecha arquivo
	arquivo_mapa.close();
}

// _______________________________________________________________________________
void Mapa::iniciarEntidades()
{
	for (int i = 1; i < 10; i++) {
		entidades.push_back(new Plataforma(i, true));
	}
}

// _______________________________________________________________________________
void Mapa::desenharMapa(sf::RenderTarget& janela)
{
	/* desenha todas as entidades */
	for (int x = 0; x < this->tamMapaX; x++) {
		for (int y = 0; y < this->tamMapaY; y++) {
			int ent = mapa[x][y] - 1;
			if (ent > 0) {
				entidades[ent]->setPosicao(x * this->tamEntidade, y * this->tamEntidade);
				entidades[ent]->desenharEntidade(janela);
			}
		}
	}
}
