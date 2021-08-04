#include "stdafx.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
VelhoOeste::VelhoOeste(JogoInfo* pji, int n_jogadores)
	: Fase(pji, n_jogadores)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/velho_oeste.png");
	this->iniciarMapa("./Recursos/mapas/velho_oeste.txt", 1, 17);
	this->iniciarGerenciadorColisoes();
	this->iniciarGeradorProjeteis();
	this->jogoInfo->getTocaDisco()->tocarFallenDown();
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
	if (pausado == false) {
		this->atualizarEntidades();

		// checa se ainda tem algum jogador vivo
		if (this->listaJog.listaVazia()) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarTela(new TelaMorte(this->jogoInfo, rand() % 800));
		}
		else {
			this->gerColisoes.verificarColisoes();
			this->gerProj.CriarProjetil();
		}
	}
}

// _______________________________________________________________________________
void VelhoOeste::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (pausado) {
			if (evento_sfml.key.code == sf::Keyboard::Up)
				this->caixaPause.trocarBotao(-1); // ativa o botao de cima
			if (evento_sfml.key.code == sf::Keyboard::Down)
				this->caixaPause.trocarBotao(1); // ativa o botao de baixo
			if (evento_sfml.key.code == sf::Keyboard::Enter)
				this->realizarAcaoMenuPause();

		}
		if (evento_sfml.key.code == sf::Keyboard::Escape)
			this->pausado = (pausado == true) ? false : true;
	}
}

// _______________________________________________________________________________
void VelhoOeste::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->sprite); // background

	// desenha mapa, personagens e guis
	this->desenharEntidades(janela);
	this->textoScore.desenharGui(janela);
	this->mapa.desenharMapa(janela);

	// desenha menu pause
	if(pausado) {
		this->caixaPause.desenharCaixaPause(janela);
	}
}

void VelhoOeste::iniciarInimigos()
{

	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(630.f, 410.f), 2700));
	//this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(370.f, 310.f), 140));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(510.f, 110.f), 1700));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(700.f, 50.f), 1950));
	this->listaIni.incluirInimigo(new Bruxa("./Recursos/Imagens/Personagens/bruxa.png", sf::Vector2f(1100.f, 280.f), 2800));

}