#pragma once
#include "Plataforma.h"
#include "Cactus.h"
#include "Espinho.h"
#include "AreiaDasAlmas.h"
#include "JogoInfo.h"
#include "configuracoes.h"

class Mapa
{
private:
	std::vector<std::vector<int > > mapa;
	std::vector<std::vector<int > > posLivres; // posicoes que pode receber um obstaculo
	std::vector<Entidade* > entidades;

	// os arquivos estão nomeados como "<numero>.png"
	// armazena o numero de inicio e fim de cada tipo de de entidade
	int inicioPlataformas;
	int qtdPlataformas;

public:
	// construtoras e destrutoras
	Mapa();
	~Mapa();

	// Setters e getters
	const int blocoAtual(sf::Vector2f pos) const;
	Entidade* getEntidade(const int i) const;

	// metodos de inicialização
	void iniciarMapa(std::string diretorio , int ini, int qtd, int tipo = 1);
	void carregarMapa(std::string diretorio);
	void iniciaPosicoesLivres();
	void iniciarEntidades(int tipo);

	// metodo de renderização
	void desenharMapa(sf::RenderTarget& janela);
};