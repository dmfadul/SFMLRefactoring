#pragma once
#include "Ente.h"

/* Classe do menu de Pontuação */
class Pontuacao :
    public Ente
{
private:
    class Linha {
    private:
        // Variaveis
        sf::Text nome;
        sf::Text ponto;
        sf::Font fonte;
        int tam_char;

    public:
        // Construtores e Destrutores
        Linha() { this->tam_char = 0; }
        Linha(sf::Vector2f pos, sf::Vector2f tam, std::string n, std::string p) 
        {
            this->tam_char = 30;
            // carrega a fonte
            if (!this->fonte.loadFromFile("./Recursos/Fontes/Bebas.ttf")) {
                std::cout << "PONTUACAO::FALHA AO CARREGAR FONTE" << std::endl;
            }

            // nome
            this->nome.setFont(this->fonte);
            this->nome.setString(n);
            this->nome.setCharacterSize(this->tam_char);
            this->nome.setPosition(pos.x + 20.f, pos.y + 15.f);
            this->nome.setFillColor(sf::Color::White);

            // pontuacao
            this->ponto.setFont(this->fonte);
            this->ponto.setString(p);
            this->ponto.setCharacterSize(this->tam_char);
            this->ponto.setPosition(pos.x + tam.x/2.f, pos.y + 15.f);
            this->ponto.setFillColor(sf::Color::White);

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
    gui::Botao botaoVoltar;
    std::vector<Linha* > linhas;

public:
    // Construtoras e Destrutoras
    Pontuacao();
    Pontuacao(JogoInfo* pji);
    ~Pontuacao();

    // Métodos de Inicialização
    void iniciarCaixa();
    void iniciarBotao();
    void iniciarLinhas();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);
};
