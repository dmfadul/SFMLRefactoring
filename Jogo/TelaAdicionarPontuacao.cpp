#include "stdafx.h"
#include "TelaAdicionarPontuacao.h"

// _______________________________________________________________________________
TelaAdicionarPontuacao::TelaAdicionarPontuacao(JogoInfo* pji, int s)
	:Tela(pji), score(s)
{
	this->iniciarTextos();
}

// _______________________________________________________________________________
TelaAdicionarPontuacao::~TelaAdicionarPontuacao()
{
}

// _______________________________________________________________________________
void TelaAdicionarPontuacao::iniciarTextos()
{
	this->nomeInput = "";

	// inicia texto score
	this->textoScore.setFont(this->fonte);
	this->textoScore.setString("SCORE: " + std::to_string(score));
	this->textoScore.setCharacterSize(50);
	this->textoScore.setFillColor(sf::Color::White);
	this->textoScore.setPosition(TAM_JANELA_X / 2.f - this->textoScore.getGlobalBounds().width / 2.f, 250.f);

	// inicia texto Digite seu nome;
	this->digiteNome.setFont(this->fonte);
	this->digiteNome.setString("Digite seu nome: ");
	this->digiteNome.setCharacterSize(50);
	this->digiteNome.setFillColor(sf::Color::White);
	this->digiteNome.setPosition(TAM_JANELA_X / 2.f - this->digiteNome.getGlobalBounds().width / 2.f, TAM_JANELA_Y / 2.f);

	// inicia texto nome
	this->nome.setFont(this->fonte);
	this->nome.setString(this->nomeInput);
	this->nome.setCharacterSize(50);
	this->nome.setFillColor(sf::Color::White);
	this->nome.setPosition(this->digiteNome.getPosition().x + this->digiteNome.getGlobalBounds().width + 10.f, TAM_JANELA_Y / 2.f);
}

// _______________________________________________________________________________
void TelaAdicionarPontuacao::adicionarPontuacao()
{
	/* Adiciona uma nova pontuação no arquivo de pontuacoes */
	std::ofstream arquivo_pontuacao;
	arquivo_pontuacao.open("./Recursos/dados/pontuacao.txt", std::ios::out | std::ios::app);
	arquivo_pontuacao << "\n" << this->nomeInput << " " << this->score;
	arquivo_pontuacao.close();
}

// _______________________________________________________________________________
void TelaAdicionarPontuacao::atualizar()
{
}

// _______________________________________________________________________________
void TelaAdicionarPontuacao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		// adiciona a nova pontuação e vai a tela de pontuacao
		if (evento_sfml.key.code == sf::Keyboard::Enter && this->nomeInput.size() >= 3) {
			this->adicionarPontuacao();
			this->jogoInfo->getTocaDisco()->tocarMusicaInicio();
			this->jogoInfo->trocarEnte(new TelaPontuacao(this->jogoInfo)); 
		}
	}
	// recebe input do usuario
	else if (evento_sfml.type == sf::Event::TextEntered) 
	{
		if (evento_sfml.text.unicode == '\b' && this->nomeInput.size() > 0) // tecla backspace
			this->nomeInput.erase(this->nomeInput.size() - 1, 1);
		else if (((evento_sfml.text.unicode > 64) && (evento_sfml.text.unicode < 91)) // maisculas
			|| ((evento_sfml.text.unicode > 96) && (evento_sfml.text.unicode < 123))) // minusculas
			this->nomeInput += evento_sfml.text.unicode;

		// texto nome recebe o conteudo do input
		this->nome.setString(this->nomeInput);
	}
}

// _______________________________________________________________________________
void TelaAdicionarPontuacao::desenhar(sf::RenderTarget& janela)
{
	/*Desenha todos os textos na tela*/
	janela.draw(this->textoScore);
	janela.draw(this->digiteNome);
	janela.draw(this->nome);
}
