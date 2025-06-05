#include "Core/stdafx.h"
#include "States/Menu.h"

// _______________________________________________________________________________
Menu::Menu():
	Ente()
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
void Menu::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame na janela */
	janela.draw(this->sprite);
	janela.draw(this->caixaBotoes);

	// desenha botoes
	for (auto& botao : this->botoes)
		botao.second->desenharBotao(janela);
}

