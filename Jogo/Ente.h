#pragma once

#include "Botao.h"

// Armazena informações de todos os entes
struct EnteInfo;

/* Classe abstrata de Entes */
class Ente
{
protected:
	// Variaveis
    EnteInfo* enteInfo;

    // background
    sf::Texture texturaBg;
    sf::Sprite background;

public:
    // Construtoras e Destrutoras
    Ente();
    Ente(EnteInfo* pei);
    virtual ~Ente();

    // Metodos de Inicialização
    void iniciarBackground(std::string diretorio);

    // Setters e getters
    const bool getEncerrar() const;
    void setEncerrar(const bool e);

    // Métodos de Atualização
    virtual void atualizar() = 0;
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;

    // Métodos de Renderização
    virtual void desenhar(sf::RenderTarget& janela) = 0;

};

/* Estrutura que guarda as informações do Ente. */
struct EnteInfo {
    // Variaveis
    float tamEntidade = 0.f;
    bool encerrarEnte = false;
    sf::RenderWindow* janela = NULL;
    std::stack<Ente* >* entes = NULL;
};

