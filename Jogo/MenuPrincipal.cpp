#include "stdafx.h"
#include "MenuPrincipal.h"

// _______________________________________________________________________________
MenuPrincipal::MenuPrincipal():
	Ente(NULL)
{
	this->botaoAtivo = NovoJogo;
}

// _______________________________________________________________________________
MenuPrincipal::MenuPrincipal(EnteInfo* pei):
	Ente(pei)
{
	this->botaoAtivo = NovoJogo;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/background_menu.png");
}

// _______________________________________________________________________________
MenuPrincipal::~MenuPrincipal()
{
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuPrincipal::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[NovoJogo] = new gui::Botao(this->enteInfo->janela->getSize().x / 2 - 100.f, 200.f, "Novo Jogo");
	this->botoes[Pontuacao] = new gui::Botao(this->enteInfo->janela->getSize().x / 2 - 100.f, 260.f, "Pontuação");
	this->botoes[Sair] = new gui::Botao(this->enteInfo->janela->getSize().x / 2 - 100.f, 380.f, "Sair");
	this->botoes[Sair]->setCorAtivado(sf::Color::Red); // botao sair será vermelho quando ativo

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300.f, 270.f));
	this->caixaBotoes.setPosition(this->enteInfo->janela->getSize().x /2 - this->caixaBotoes.getGlobalBounds().width / 2, 180.f);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuPrincipal::atualizar()
{
}

// _______________________________________________________________________________
void MenuPrincipal::atualizarEventos(sf::Event& evento_sfml)
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
void MenuPrincipal::trocarBotao(int direcao)
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

// _______________________________________________________________________________
void MenuPrincipal::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == NovoJogo)
		this->enteInfo->entes->push(new VelhoOeste(this->enteInfo));

	if (this->botaoAtivo == Sair)
		this->enteInfo->janela->close();

}

// _______________________________________________________________________________
void MenuPrincipal::desenhar(sf::RenderWindow& janela)
{
	/* Desenha o novo frame na janela */

	janela.draw(this->background);
	janela.draw(this->caixaBotoes);

	// desenha botoes
	for (auto& botao : this->botoes)
		botao.second->desenharBotao(janela);
}
