#pragma once
#include "UI/Tela.h"
#include "Core/GerenciadorBotoes.h"
#define TAM_CHAR 30
#define TAM_CAIXA_X 800
#define TAM_CAIXA_Y 400

/* Classe do menu de Pontua��o */
class TelaPontuacao :
    public Tela, public GerenciadorBotoes
{
private:
    class Linha {
    private:
        // Variaveis
        sf::Text nome;
        sf::Text ponto;
        sf::Font fonte;

    public:
        // Construtores e Destrutores
        Linha() { }
        Linha(sf::Vector2f pos, std::string n, std::string p, int colocacao) 
        {
            // carrega a fonte
            if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")) {
                std::cout << "PONTUACAO::FALHA AO CARREGAR FONTE" << std::endl;
            }

            // nome
            this->nome.setFont(this->fonte);
            this->nome.setString(std::to_string(colocacao)+ ".\t" +n);
            this->nome.setCharacterSize(TAM_CHAR);
            this->nome.setPosition(pos.x + 20.f, pos.y + 15.f + 30.f * colocacao);
            this->nome.setFillColor(sf::Color(255,255,255,150));

            // pontuacao
            this->ponto.setFont(this->fonte);
            this->ponto.setString(p);
            this->ponto.setCharacterSize(TAM_CHAR);
            this->ponto.setPosition(pos.x + TAM_CAIXA_X / 2.f, pos.y + 15.f + 30.f * colocacao);
            this->ponto.setFillColor(sf::Color(255, 255, 255, 150));
        }
        ~Linha() { } 

        // desenha a nova linha
        void desenharLinha(sf::RenderTarget& janela) 
        {
            janela.draw(this->nome);
            janela.draw(this->ponto);
        }
    };

    // Variaveis
    sf::RectangleShape caixaPontuacao;
    sf::Text nome;
    sf::Text pontuacao;
    std::vector<Linha* > linhas;

public:
    // Construtoras e Destrutoras
    TelaPontuacao();
    ~TelaPontuacao();

    // M�todos de Inicializa��o
    void iniciarCaixa();
    void iniciarBotao();
    void carregarPontuacao();

    // M�todos de Atualiza��o
    void adicionarLinha(std::string nome, std::string pontuacao, int pos);
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
};
