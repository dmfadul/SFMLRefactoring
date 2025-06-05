#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(int n_jogadores, bool carregar_jogo)
	: Fase(n_jogadores)
{
	if (carregar_jogo)
		this->carregarJogo();
	else
		this->iniciarPersonagens();

	this->iniciarBackground("./Recursos/Imagens/backgrounds/ninho_do_dragao.png");
	this->iniciarMapa("./Recursos/mapas/ninho_dragao.txt", 101, 17, 2);
	this->iniciarGerenciadorColisoes();
	this->iniciarGeradorProjeteis();
	this->atualizarScore(0);
	JogoInfo::getInstancia()->getTocaDisco()->tocarSpearOfJustice();
	this->nome = "NINHO_DO_DRAGAO";
}

// _______________________________________________________________________________
NinhoDoDragao::~NinhoDoDragao()
{
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizar()
{
	if (pausado == false) {
		// atualiza as entidades
		this->atualizarEntidades();

		// checa se ainda tem algum jogador vivo
		if (this->listaJog.listaVazia()) {
			JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
			JogoInfo::getInstancia()->trocarEnte(new TelaAdicionarPontuacao(PersonagemInfo::getScore()));
			PersonagemInfo::setScore(0);
		}
		// checa se todos os inimigos foram eliminados
		else if (this->listaIni.listaVazia()) {
			JogoInfo::getInstancia()->getTocaDisco()->pararMusica();
			JogoInfo::getInstancia()->trocarEnte(new TelaAdicionarPontuacao(PersonagemInfo::getScore()));
		}
		// se ainda houverem jogadores e inimigos 
		else
		{
			this->gerProj.ExcluirProjetil();
			this->gerColisoes.verificarColisoes();

			// invoca novo inimigo
			if (this->timerInvocarInimigo.getElapsedTime().asMilliseconds() > 7000) {
				this->invocarInimigo();
		}

		
		}
	}
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizarEventos(sf::Event& evento_sfml)
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
void NinhoDoDragao::invocarInimigo()
{
	/* Spawna cobra ou bruxa aleatoriamente. */
	Inimigo* inimigo = 0;
	
	if(rand() % 2 == 0)
		inimigo = static_cast<Inimigo*>(new Bruxa(sf::Vector2f((float)(rand() % TAM_JANELA_X), 0.f), &this->gerProj, rand() % 1500 + 1000));
	else
		inimigo = static_cast<Cobra*>(new Cobra(&this->listaJog, sf::Vector2f((float)(rand() % TAM_JANELA_X), 0.f)));

	this->listaIni.incluirInimigo(static_cast<Inimigo*>(inimigo));
	this->listaEntidades.incluirEntidade(static_cast<Entidade*>(inimigo));
	this->timerInvocarInimigo.restart();
}

// _______________________________________________________________________________
void NinhoDoDragao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame */
	janela.draw(this->sprite); // background

	// desenha mapa, personagens e GUIs
	this->desenharEntidades(janela);
	this->textoScore.desenharGui(janela);
	this->mapa.desenharMapa(janela);

	// desenha menu pause
	if (pausado) {
		this->caixaPause.desenharCaixaPause(janela);
	}
	
}

// _______________________________________________________________________________
void NinhoDoDragao::iniciarInimigos()
{
	this->listaIni.incluirInimigo(new Dragao(sf::Vector2f(1000.f, 450.f), &this->gerProj));

	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != 0) {
		Inimigo* pInimigo = elInimigo->getInfo();
		this->listaEntidades.incluirEntidade(static_cast<Entidade*>(pInimigo));
		elInimigo = elInimigo->getProximo();
	}
}
