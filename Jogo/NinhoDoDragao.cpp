#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji, int n_jogadores, bool carregar_jogo)
	: Fase(pji, n_jogadores)
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
	this->jogoInfo->getTocaDisco()->tocarSpearOfJustice();
	this->qtdMaxBruxas = rand() % 4 + 2;
	this->qtdBruxas = 0;
	this->nome = "NINHO_DO_DRAGAO";
}

// _______________________________________________________________________________
NinhoDoDragao::~NinhoDoDragao()
{
	this->jogoInfo = NULL;
}

// _______________________________________________________________________________
void NinhoDoDragao::atualizar()
{
	if (pausado == false) {
		// atualiza as entidades
		this->atualizarEntidades();

		// checa se ainda tem algum jogador vivo
		if (this->listaJog.listaVazia()) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarEnte(new TelaAdicionarPontuacao(this->jogoInfo, PersonagemInfo::getScore()));
			PersonagemInfo::setScore(0);
		}
		// checa se todos os inimigos foram eliminados
		else if (this->listaIni.listaVazia()) {
			this->jogoInfo->getTocaDisco()->pararMusica();
			this->jogoInfo->trocarEnte(new TelaAdicionarPontuacao(this->jogoInfo, PersonagemInfo::getScore()));
		}
		// se ainda houverem jogadores e inimigos 
		else
		{
			this->gerProj.ExcluirProjetil();
			this->gerColisoes.verificarColisoes();
		}

		// invoca nova bruxa
		if (this->timerInvocarBruxa.getElapsedTime().asMilliseconds() > 2000 && this->qtdBruxas < this->qtdMaxBruxas) {
			this->invocarBruxa();
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

void NinhoDoDragao::invocarBruxa()
{
	Bruxa* bruxa = new Bruxa(sf::Vector2f(rand() % TAM_JANELA_X, 0.f), &this->gerProj, rand() % 1500 + 1000);
	this->listaIni.incluirInimigo(static_cast<Inimigo*>(bruxa));
	this->listaEntidades.incluirEntidade(static_cast<Entidade*>(bruxa));

	this->qtdBruxas++;
	this->timerInvocarBruxa.restart();
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

void NinhoDoDragao::iniciarInimigos()
{
	this->listaIni.incluirInimigo(new Dragao(sf::Vector2f(1000.f, 450.f), &this->gerProj));

	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		this->listaEntidades.incluirEntidade(static_cast<Entidade*>(pInimigo));
		elInimigo = elInimigo->getProximo();
	}

}
