#pragma once
#include "UI/Tela.h"
#include "UI/TelaPontuacao.h"
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
    TelaAdicionarPontuacao(int s = 0);
    ~TelaAdicionarPontuacao();

    // Metodos de inicializa��o
    void iniciarTextos();

    // M�todos de Atualiza��o
    void adicionarPontuacao();
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // M�todos de Renderiza��o
    void desenhar(sf::RenderTarget& janela);
};

