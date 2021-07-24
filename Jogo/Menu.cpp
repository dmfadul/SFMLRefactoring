#include "stdafx.h"
#include "Menu.h"

// _______________________________________________________________________________
Menu::Menu(JogoInfo* pji):
	Ente(pji), botoes()
{
	this->botaoAtivo = false;
}

// _______________________________________________________________________________
Menu::~Menu()
{
}

// _______________________________________________________________________________
void Menu::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Up)
			this->trocarBotao(-1); // ativa o botao de cima
		if (evento_sfml.key.code == sf::Keyboard::Down)
			this->trocarBotao(1); // ativa o botao de baixo
		if (evento_sfml.key.code == sf::Keyboard::Enter)
			this->GerenciarCliqueBotao();
	}
}

// _______________________________________________________________________________
void Menu::trocarBotao(int direcao)
{
	/* Muda o botao ativo */

	// desativa o botao atual
	this->botoes[this->botaoAtivo]->desativar();

	// troca o botao ativo
	if (this->botaoAtivo + direcao >= 0)
		this->botaoAtivo = (this->botaoAtivo + direcao) % static_cast<int>(this->botoes.size());
	else
		this->botaoAtivo = static_cast<int>(this->botoes.size()) - 1;

	// ativa o novo botao atual
	this->botoes[this->botaoAtivo]->ativar();
}

void Menu::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame na janela */
	janela.draw(this->background);
	janela.draw(this->caixaBotoes);

	// desenha botoes
	for (auto& botao : this->botoes)
		botao.second->desenharBotao(janela);
}
