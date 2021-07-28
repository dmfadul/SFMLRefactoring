#include "stdafx.h"
#include "Mapa.h"

// _______________________________________________________________________________
Mapa::Mapa(std::string diretorio, int ini, int qtd)
	:inicioPlataformas(ini), qtdPlataformas(qtd)
{
	this->carregarMapa(diretorio);
	this->iniciarEntidades();
}

// _______________________________________________________________________________
Mapa::~Mapa()
{
	// desaloca mapa
	for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
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
	this->mapa.resize(TAM_MAPA_X);
	for (unsigned int i = 0; i < TAM_MAPA_X; i++)
		this->mapa[i].resize(TAM_MAPA_Y);

	// abre o arquivo com o mapa
	std::fstream arquivo_mapa;
	arquivo_mapa.open(diretorio, std::ios::in);
	int n = 0;

	// salva o mapa na matriz mapa
	for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
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
	/* Inicia todas as plataformas e obstaculos*/
	// inicia todas as plataformas
	for (int i = 0; i < this->qtdPlataformas; i++) {
		this->entidades.push_back(new Plataforma(this->inicioPlataformas + i));
	}
	
	this->entidades.push_back(new Cactus(1));
}

// _______________________________________________________________________________
void Mapa::desenharMapa(sf::RenderTarget& janela)
{
	/* desenha todas as entidades */
	for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
		for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
			int ent = mapa[x][y] - 1;
			if (ent >= 0) {
				entidades[ent]->setPosicao(static_cast<const float>(x * TAM_BLOCO), static_cast<const float>(y * TAM_BLOCO));
				entidades[ent]->desenharEntidade(janela);
			}
		}
	}
}
