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
	this->qtdMaxCobras = rand() % 4 + 3;
	this->qtdCobras = 0;
}

// _______________________________________________________________________________
VelhoOeste::~VelhoOeste()
{
	this->jogoInfo = NULL;
}

void VelhoOeste::invocarCobra()
{
	this->listaIni.incluirInimigo(new Cobra(&this->listaJog, sf::Vector2f((float)(rand() % TAM_JANELA_X), 0.f)));
	this->qtdCobras++;
	this->timerInvocarCobra.restart();
}

// _______________________________________________________________________________
void VelhoOeste::atualizar()
{
	if (pausado == false) {
		// invoca nova cobra
		if (this->timerInvocarCobra.getElapsedTime().asMilliseconds() > 5000 && this->qtdCobras < this->qtdMaxCobras) {
			this->invocarCobra();
		}

		// atualiza as entidades
		this->atualizarEntidades();

		// checa se ainda tem algum jogador vivo
		if (this->listaJog.listaVazia()) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarTela(new TelaMorte(this->jogoInfo, rand() % 800));
		}
		else {
			this->gerColisoes.verificarColisoes();
			this->gerProj.CriarProjetil();
			this->gerProj.ExcluirProjetil();
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
	this->listaIni.incluirInimigo(new Bruxa(sf::Vector2f(630.f, 410.f), 2700));
	this->listaIni.incluirInimigo(new Bruxa(sf::Vector2f(500.f, 110.f), 1600));
	this->listaIni.incluirInimigo(new Bruxa(sf::Vector2f(700.f, 50.f), 1850));
	this->listaIni.incluirInimigo(new Bruxa(sf::Vector2f(1100.f, 280.f), 2770));
}