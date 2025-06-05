#pragma once
#include "Entities/Plataforma.h"
#include "Entities/Cactus.h"
#include "Entities/Espinho.h"
#include "Entities/AreiaDasAlmas.h"
#include "Utils/JogoInfo.h"
#include "configuracoes.h"

class Mapa
{
private:
	std::vector<std::vector<int > > mapa;
	std::vector<std::vector<int > > posLivres; // posicoes que pode receber um obstaculo
	std::vector<Obstaculo* > blocos;

	// os arquivos est�o nomeados como "<numero>.png"
	// armazena o numero de inicio e fim de cada tipo de de entidade
	int inicioPlataformas;
	int qtdPlataformas;

public:
	// construtoras e destrutoras
	Mapa();
	~Mapa();

	// Setters e getters
	const int blocoAtual(sf::Vector2f pos) const;
	Obstaculo* getBloco(const int i) const;

	// metodos de inicializa��o
	void iniciarMapa(std::string diretorio , int ini, int qtd, int tipo = 1);
	void carregarMapa(std::string diretorio);
	void iniciaPosicoesLivres();
	void iniciarEntidades(int tipo);

	// metodo de renderiza��o
	void desenharMapa(sf::RenderTarget& janela);
};