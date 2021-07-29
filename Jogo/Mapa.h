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

	// os arquivos estão nomeados como "<nomemapa><numero>.png"
	// armazena o numero de inicio e fim de cada tipo de de entidade
	int inicioPlataformas;
	int qtdPlataformas;
	int qtdObstaculos;
public:
	// construtoras e destrutoras
	Mapa(std::string diretorio = "", int ini = 0, int qtd = 0);
	~Mapa();

	// setter e getters
	Obstaculo* getObsAleatorio();

	// metodos de inicialização
	void carregarMapa(std::string diretorio);
	void iniciaPosicoesLivres();
	void iniciarEntidades();

	// metodo de renderização
	void desenharMapa(sf::RenderTarget& janela);
};