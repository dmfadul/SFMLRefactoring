#include "stdafx.h"
#include "NinhoDoDragao.h"
#include "VelhoOeste.h"

// _______________________________________________________________________________
NinhoDoDragao::NinhoDoDragao(JogoInfo* pji, int n_jogadores)
	: Fase(pji, n_jogadores)
{
	this->iniciarPersonagens();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/ninho_do_dragao.png");
	this->iniciarMapa("./Recursos/mapas/ninho_dragao.txt", 101, 17, 2);
	this->iniciarGerenciadorColisoes();
	this->iniciarGeradorProjeteis();
	this->jogoInfo->getTocaDisco()->tocarSpearOfJustice();
	this->atualizarScore(PersonagemInfo::getScore());
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
	this->listaIni.incluirInimigo(new Dragao(sf::Vector2f(1000.f, 500.f), &this->gerProj));

	Lista<Inimigo>::Elemento<Inimigo>* elInimigo = this->listaIni.getPrimeiro();
	while (elInimigo != NULL) {
		Inimigo* pInimigo = elInimigo->getInfo();
		this->listaEntidades.incluirEntidade(static_cast<Entidade*>(pInimigo));
		elInimigo = elInimigo->getProximo();
	}
}
