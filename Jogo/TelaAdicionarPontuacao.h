#pragma once
#include "Tela.h"
#include "TelaPontuacao.h"
class TelaAdicionarPontuacao :
    public Tela
{
private:
    // variaveis
    int score;
    sf::Text textoScore;
    sf::Text digiteNome;
    sf::Text nome;
    std::string nomeInput;

public:
    // construtores e destrutoras
    TelaAdicionarPontuacao(JogoInfo* pji = NULL, int s = 0);
    ~TelaAdicionarPontuacao();

    // Metodos de inicialização
    void iniciarTextos();

    // Métodos de Atualização
    void adicionarPontuacao();
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);
};

