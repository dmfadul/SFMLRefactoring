#include "Core/stdafx.h"
#include "UI/TelaPontuacao.h"

// _______________________________________________________________________________
TelaPontuacao::TelaPontuacao() :
	Tela()
{
	// chama os metodos de inicializa��o
	this->iniciarBackground("./Recursos/Imagens/backgrounds/pontuacao.png");
	this->iniciarCaixa();
	this->iniciarBotao();
	this->carregarPontuacao();
}

// _______________________________________________________________________________
TelaPontuacao::~TelaPontuacao()
{
	for (auto& linha : this->linhas)
		delete linha;
}

// _______________________________________________________________________________
void TelaPontuacao::iniciarCaixa()
{
	/* Inicia a caixa que engloba a lista de pontua�oes */
	this->caixaPontuacao.setFillColor(sf::Color(0, 0, 0, 150));

	// Inicia a caixa
	this->caixaPontuacao.setSize(sf::Vector2f(TAM_CAIXA_X, TAM_CAIXA_Y));

	// centraliza na tela
	this->caixaPontuacao.setPosition(
		TAM_JANELA_X / 2 - TAM_CAIXA_X / 2,
		TAM_JANELA_Y / 2 - TAM_CAIXA_Y / 2
	);

	// INICIA TEXTO DA CAIXA
	// nome
	this->nome.setFont(this->fonte);
	this->nome.setString("NOME:");
	this->nome.setCharacterSize(TAM_CHAR);
	this->nome.setPosition(this->caixaPontuacao.getPosition().x +20.f, this->caixaPontuacao.getPosition().y + 10.f);
	this->nome.setFillColor(sf::Color::White);

	// pontuacao
	this->pontuacao.setFont(this->fonte);
	this->pontuacao.setString("PONTUA��O:");
	this->pontuacao.setCharacterSize(TAM_CHAR);
	this->pontuacao.setPosition(
		this->caixaPontuacao.getPosition().x + TAM_CAIXA_X / 2.f,
		this->caixaPontuacao.getPosition().y + 10.f
	);
	this->pontuacao.setFillColor(sf::Color::White);
}

// _______________________________________________________________________________
void TelaPontuacao::iniciarBotao()
{
	/* Inicia o botao de voltar */
	this->botoes[0] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, TAM_JANELA_Y - 100.f, "Voltar");
	this->botoes[0]->ativar();
}

// _______________________________________________________________________________
void TelaPontuacao::carregarPontuacao()
{
	std::string n;
	int p;
	std::multimap<int, std::string, std::greater<int>> ranking;
	std::multimap<int, std::string>::iterator it;

	// abre o arquivo com o pontuacao
	std::fstream arquivo_pontuacao;
	try{
		arquivo_pontuacao.open("./Recursos/dados/pontuacao.txt", std::ios::in);
	}
	catch (...){
		std::cerr << "MAPA::CARREGARPONTUCAO FALHA AO CARREGAR PONTUACAO " << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// adiciona as pontua�oes em um multimap ordenado
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
void TelaPontuacao::adicionarLinha(std::string nome, std::string pontuacao, int pos)
{
	this->linhas.push_back(new Linha(this->caixaPontuacao.getPosition(), nome, pontuacao, pos));
}


// _______________________________________________________________________________
void TelaPontuacao::atualizar()
{
}

// _______________________________________________________________________________
void TelaPontuacao::atualizarEventos(sf::Event& evento_sfml)
{
	/* Checa por eventos SFML*/
	if (evento_sfml.type == sf::Event::KeyReleased)
	{
		if (evento_sfml.key.code == sf::Keyboard::Enter)
			JogoInfo::getInstancia()->popEnte(); // volta ao menu principal
	}
}
// _______________________________________________________________________________
void TelaPontuacao::desenhar(sf::RenderTarget& janela)
{
	/* Desenha novo frame*/
	janela.draw(this->sprite);
	janela.draw(this->caixaPontuacao);
	janela.draw(this->nome);
	janela.draw(this->pontuacao);
	this->botoes[0]->desenharBotao(janela);

	for (auto& linha : this->linhas)
		linha->desenharLinha(janela);
}		
