#include "stdafx.h"
#include "Pontuacao.h"

// _______________________________________________________________________________
Pontuacao::Pontuacao()
{
}

// _______________________________________________________________________________
Pontuacao::Pontuacao(JogoInfo* pji) :
	Tela(pji)
{
	// chama os metodos de inicialização
	this->iniciarBackground("./Recursos/Imagens/backgrounds/pontuacao.png");
	this->iniciarCaixa();
	this->iniciarBotao();
	this->carregarPontuacao();
}

// _______________________________________________________________________________
Pontuacao::~Pontuacao()
{
	this->jogoInfo = NULL;
	for (auto& linha : this->linhas)
		delete linha;
}

// _______________________________________________________________________________
void Pontuacao::iniciarCaixa()
{
	/* Inicia a caixa que engloba a lista de pontuaçoes */
	this->caixaPontuacao.setFillColor(sf::Color(0, 0, 0, 150));

	// Inicia a caixa
	this->caixaPontuacao.setSize(sf::Vector2f(TAM_CAIXA_X, TAM_CAIXA_Y));

	// centraliza na tela
	this->caixaPontuacao.setPosition(
		TAM_JANELA_X / 2 - TAM_CAIXA_X / 2,
		TAM_JANELA_Y / 2 - TAM_CAIXA_Y / 2
	);

	// INICIA TEXTO DA CAIXA
	// carrega a fonte
	if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")) {
		std::cout << "PONTUACAO::FALHA AO CARREGAR FONTE" << std::endl;
	}

	// nome
	this->nome.setFont(this->fonte);
	this->nome.setString("NOME:");
	this->nome.setCharacterSize(TAM_CHAR);
	this->nome.setPosition(this->caixaPontuacao.getPosition().x +20.f, this->caixaPontuacao.getPosition().y + 10.f);
	this->nome.setFillColor(sf::Color::White);

	// pontuacao
	this->pontuacao.setFont(this->fonte);
	this->pontuacao.setString("PONTUAÇÃO:");
	this->pontuacao.setCharacterSize(TAM_CHAR);
	this->pontuacao.setPosition(
		this->caixaPontuacao.getPosition().x + TAM_CAIXA_X / 2.f,
		this->caixaPontuacao.getPosition().y + 10.f
	);
	this->pontuacao.setFillColor(sf::Color::White);
}

// _______________________________________________________________________________
void Pontuacao::iniciarBotao()
{
	/* Inicia o botao de voltar */
	this->botaoVoltar.iniciarBotao(
		TAM_JANELA_X / 2 - 100.f,
		TAM_JANELA_Y - 100.f,
		"Voltar"
	);
	this->botaoVoltar.ativar();
}

// _______________________________________________________________________________
void Pontuacao::carregarPontuacao()
{
	std::string n;
	int p;
	std::multimap<int, std::string, std::greater<int>> ranking;
	std::multimap<int, std::string>::iterator it;

	// abre o arquivo com o pontuacao
	std::fstream arquivo_pontuacao;
	arquivo_pontuacao.open("./Recursos/dados/pontuacao.txt", std::ios::in);

	// adiciona as pontuaçoes em um multimap ordenado
	while (arquivo_pontuacao >> n && arquivo_pontuacao >> p) {
		ranking.insert({p, n});
	}
	// adiciona as linhas (APENAS OS 10 PRIMEIROS)
	int pos = 1;
	for (it = ranking.begin();  it != ranking.end() && pos <= 10 ; it++, pos++)
		this->adicionarLinha(it->second, std::to_string(it->first), pos);

	// fecha arquivo
	arquivo_pontuacao.close();
}

// _______________________________________________________________________________
void Pontuacao::adicionarLinha(std::string nome, std::string pontuacao, int pos)
{
	this->linhas.push_back(new Linha(this->caixaPontuacao.getPosition(), nome, pontuacao, pos));
}


// _______________________________________________________________________________
void Pontuacao::atualizar()
{
}

// _______________________________________________________________________________
void Pontuacao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Enter)
			this->jogoInfo->popTela(); // volta ao menu principal
	}
}
// _______________________________________________________________________________
void Pontuacao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha novo frame*/
	janela.draw(this->sprite);
	janela.draw(this->caixaPontuacao);
	janela.draw(this->nome);
	janela.draw(this->pontuacao);
	this->botaoVoltar.desenharBotao(janela);

	for (auto& linha : this->linhas)
		linha->desenharLinha(janela);
}		
