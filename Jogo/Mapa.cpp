#include "stdafx.h"
#include "Mapa.h"

// _______________________________________________________________________________
Mapa::Mapa(JogoInfo* pji, std::string diretorio, int ini, int qtd)
	:jogoinfo(pji), inicioPlataformas(ini), qtdPlataformas(qtd)
{
	this->iniciarVariaveis();
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
	
	this->jogoinfo = NULL;

}

// _______________________________________________________________________________
void Mapa::iniciarVariaveis()
{
	this->tamMapaX = this->jogoinfo->getTamMapaX();
	this->tamMapaY = this->jogoinfo->getTamMapaY();
	this->tamEntidade = this->jogoinfo->getTamEntidade();
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
	for (int x = 0; x < this->tamMapaX; x++) {
		for (int y = 0; y < this->tamMapaY; y++) {
			int ent = mapa[x][y] - 1;
			if (ent >= 0) {
				entidades[ent]->setPosicao(x * this->tamEntidade, y * this->tamEntidade);
				entidades[ent]->desenharEntidade(janela);
			}
		}
	}
}
