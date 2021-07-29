#include "stdafx.h"
#include "Mapa.h"

// _______________________________________________________________________________
Mapa::Mapa(std::string diretorio, int ini, int qtd)
	:inicioPlataformas(ini), qtdPlataformas(qtd)
{
	this->carregarMapa(diretorio);
	this->iniciaPosicoesLivres();
	this->iniciarEntidades();
}

// _______________________________________________________________________________
Mapa::~Mapa()
{
	// desaloca mapa e posicoes livres
	for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
			this->mapa[x][y] = NULL;
			this->posLivres[x][y] = NULL;
		}
	}

	// desaloca plataformas
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
	arquivo_mapa.close();
}

// _______________________________________________________________________________
void Mapa::iniciaPosicoesLivres()
{
	/* aloca memoria suficiente*/
	this->posLivres.resize(TAM_MAPA_X);
	for (unsigned int i = 0; i < TAM_MAPA_X; i++)
		this->posLivres[i].resize(TAM_MAPA_Y);

	// inicia posicoes que podem recebem um obstaculo
	for (unsigned int y = 0; y < TAM_MAPA_Y - 1; y++) {
		for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
			if ((this->mapa[x][y + (size_t)(1)] == 2 || this->mapa[x][y + (size_t)(1)] == 8) && this->mapa[x][y] == 0) // se for uma plataforma
				this->posLivres[x][y] = 1;
			else
				this->posLivres[x][y] = 0;
		}
	}
}

// _______________________________________________________________________________
void Mapa::iniciarEntidades()
{
	/* Inicia todas as plataformas e obstaculos*/
	// inicia todas as plataformas
	for (int i = 0; i < this->qtdPlataformas; i++) {
		this->entidades.push_back(static_cast<Entidade* >(new Plataforma(this->inicioPlataformas + i)));
	}
	
	// define as posiçoes dos obstaculos
	for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
		for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
			if (posLivres[x][y] == 1 && rand() % 3 == 0)
				this->mapa[x][y] = this->qtdPlataformas + rand() % 3 + 1;
		}
	}

	// incia obstaculos;
	this->entidades.push_back(static_cast<Entidade*>(new Cactus(1)));
	this->entidades.push_back(static_cast<Entidade*>(new Espinho(2)));
	this->entidades.push_back(static_cast<Entidade*>(new AreiaDasAlmas(3)));
}

// _______________________________________________________________________________
void Mapa::desenharMapa(sf::RenderTarget& janela)
{
	/* desenha todas as entidades */
	for (unsigned int x = 0; x < TAM_MAPA_X; x++) {
		for (unsigned int y = 0; y < TAM_MAPA_Y; y++) {
			int ent = mapa[x][y] - 1;
			if (ent >= 0) {
				entidades[ent]->setPosicao((float)(x * TAM_BLOCO), (float)(y * TAM_BLOCO));
				entidades[ent]->desenharEntidade(janela);
			}
		}
	}
}
