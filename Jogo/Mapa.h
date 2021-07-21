#pragma once
#include "Plataforma.h"
#include "JogoInfo.h"

class Mapa
{
private:
	std::vector<std::vector<int > > mapa;
	std::vector<Entidade* > entidades;
	int tamMapaX;
	int tamMapaY;
	int inicioPlataformas;
	int fimPlataformas;
	int inicioObstaculos;
	int fimObstaculos;
	float tamEntidade;
	JogoInfo* jogoinfo;

public:
	Mapa(JogoInfo* pji = NULL, std::string diretorio = "");
	~Mapa();

	void carregarMapa(std::string diretorio);
	void iniciarEntidades();
	void desenharMapa(sf::RenderTarget& janela);
};
