#include "stdafx.h"
#include "MenuEscolhaFases.h"

// _______________________________________________________________________________
MenuEscolhaFases::MenuEscolhaFases(JogoInfo* pji)
	:Ente(pji)
{
	this->botaoAtivo = velho_oeste;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/bg.png");

}

// _______________________________________________________________________________
MenuEscolhaFases::~MenuEscolhaFases()
{
	this->jogoInfo = NULL;
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuEscolhaFases::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[velho_oeste] = new gui::Botao(this->jogoInfo->getJanela()->getSize().x / 2 - 100.f, 200.f, "Velho Oeste");
	this->botoes[ninho_do_dragao] = new gui::Botao(this->jogoInfo->getJanela()->getSize().x / 2 - 100.f, 260.f, "Ninho Do Dragão");
	this->botoes[voltar] = new gui::Botao(this->jogoInfo->getJanela()->getSize().x / 2 - 100.f, 380.f, "Voltar");

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300.f, 270.f));
	this->caixaBotoes.setPosition(this->jogoInfo->getJanela()->getSize().x / 2 - this->caixaBotoes.getGlobalBounds().width / 2, 180.f);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuEscolhaFases::atualizar()
{
}

// _______________________________________________________________________________
void MenuEscolhaFases::atualizarEventos(sf::Event& evento_sfml)
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
void MenuEscolhaFases::trocarBotao(int direcao)
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
void MenuEscolhaFases::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == velho_oeste)
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo)));

	else if (this->botaoAtivo == ninho_do_dragao)
		this->jogoInfo->trocarEnte(static_cast<Ente*>(new NinhoDoDragao(this->jogoInfo)));

	else if (this->botaoAtivo == voltar)
		this->jogoInfo->popEnte();
}

// _______________________________________________________________________________
void MenuEscolhaFases::desenhar(sf::RenderTarget& janela)
{
	/* Desenha o novo frame na janela */

	janela.draw(this->background);
	janela.draw(this->caixaBotoes);

	// desenha botoes
	for (auto& botao : this->botoes)
		botao.second->desenharBotao(janela);
}
