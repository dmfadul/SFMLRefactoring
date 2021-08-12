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
	this->botoes[novo_jogo] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 210.f, "NOVO JOGO");
	this->botoes[carregar_jogo] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 260.f, "CARREGAR JOGO");
	this->botoes[escolha_de_fases] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 313.f, "ESCOLHER FASE");
	this->botoes[lista_de_pontuacoes] = builderBotaoPadrao.criarBotao(TAM_JANELA_X / 2 - 100.f, 375.f, "PONTUAÇÃO");
	this->botoes[sair] = builderBotaoSair.criarBotao(TAM_JANELA_X / 2 - 100.f, 430.f, "SAIR");

	// Inicia a caixa que contem os botoes
	this->caixaBotoes.setFillColor(sf::Color(0, 0, 0, 150));
	this->caixaBotoes.setSize(sf::Vector2f(300, 350.f));
	this->caixaBotoes.setPosition(
		TAM_JANELA_X / 2 - this->caixaBotoes.getGlobalBounds().width / 2,
		TAM_JANELA_Y / 2 - this->caixaBotoes.getGlobalBounds().height / 2
	);

	this->botoes[this->botaoAtivo]->ativar();
}

// _______________________________________________________________________________
void MenuPrincipal::atualizar()
{
}

// _______________________________________________________________________________
void MenuPrincipal::carregarJogo()
{
	std::string fase;
	int n_jogadores;

	// le arquivo
	std::fstream arquivo_jogo_salvo;
	try {
		arquivo_jogo_salvo.open("./Recursos/dados/fase_salva.txt", std::ios::in);
	}
	catch (...) {
		std::cerr << "MENUPRINCIPAL::CARREGARJOGO FALHA AO CARREGAR JOGO." << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// le arquivo
	arquivo_jogo_salvo >> fase;
	arquivo_jogo_salvo >> n_jogadores;

	// inicia fase do jogo salve
	if (fase == "VELHO_OESTE")
		this->jogoInfo->pushEnte(static_cast<Ente*>(new VelhoOeste(this->jogoInfo, n_jogadores, true)));
	else if(fase == "NINHO_DO_DRAGAO")
		this->jogoInfo->pushEnte(static_cast<Ente*>(new NinhoDoDragao(this->jogoInfo, n_jogadores, true)));

	arquivo_jogo_salvo.close();
}

// _______________________________________________________________________________
void MenuPrincipal::GerenciarCliqueBotao()
{
	/* Realiza a ação vinculada com o botao ativo */

	if (this->botaoAtivo == novo_jogo)
		this->jogoInfo->pushEnte(static_cast<Ente* >(new MenuQtdJogadores(this->jogoInfo)));

	if (this->botaoAtivo == carregar_jogo)
		this->carregarJogo();
	
	else if(this->botaoAtivo == escolha_de_fases)
		this->jogoInfo->pushEnte(static_cast<Ente*>(new MenuEscolhaFases(this->jogoInfo)));

	else if (this->botaoAtivo == lista_de_pontuacoes)
		this->jogoInfo->pushEnte(static_cast<Ente* >(new TelaPontuacao(this->jogoInfo)));

	else if (this->botaoAtivo == sair)
		this->jogoInfo->setEncerrar(true);
}
