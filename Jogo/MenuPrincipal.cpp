#include "stdafx.h"
#include "MenuPrincipal.h"

// _______________________________________________________________________________
MenuPrincipal::MenuPrincipal(JogoInfo* pji):
	Menu(pji)
{
	this->botaoAtivo = novo_jogo;
	this->iniciarBotoes();
	this->iniciarBackground("./Recursos/Imagens/backgrounds/menu.png");
	this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
}

// _______________________________________________________________________________
MenuPrincipal::~MenuPrincipal()
{
	this->jogoInfo = NULL;
	// desaloca botoes
	for (auto& botao : this->botoes)
		delete botao.second;
}

// _______________________________________________________________________________
void MenuPrincipal::iniciarBotoes()
{
	/* Inicia todos os botoes do menu principal */
	this->botoes[novo_jogo] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 200.f, "Novo Jogo");
	this->botoes[escolha_de_fases] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 255.f, "Escolher Fase");
	this->botoes[lista_de_pontuacoes] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 320.f, "Pontuação");
	this->botoes[sair] = new gui::Botao(this->jogoInfo->getTamJanela().x / 2 - 100.f, 380.f, "Sair");
	this->botoes[sair]->setCorAtivado(sf::Color::Red); // botao sair será vermelho quando ativo

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300.f, 270.f));
	this->caixaBotoes.setPosition(this->jogoInfo->getTamJanela().x /2 - this->caixaBotoes.getGlobalBounds().width / 2, 180.f);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuPrincipal::atualizar()
{
}

// _______________________________________________________________________________
void MenuPrincipal::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == novo_jogo)
		this->jogoInfo->pushEnte(static_cast<Ente* >(new MenuQtdJogadores(this->jogoInfo)));
	
	else if(this->botaoAtivo == escolha_de_fases)
		this->jogoInfo->pushEnte(static_cast<Ente*>(new MenuEscolhaFases(this->jogoInfo)));

	else if (this->botaoAtivo == lista_de_pontuacoes)
		this->jogoInfo->pushEnte(static_cast<Ente* >(new Pontuacao(this->jogoInfo)));

	else if (this->botaoAtivo == sair)
		this->jogoInfo->fecharJanela();
}
