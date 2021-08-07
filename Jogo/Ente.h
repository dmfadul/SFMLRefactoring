#pragma once

#include "Botao.h"
#include "JogoInfo.h"
#include "configuracoes.h"
#include "Entidade.h"

/* Classe abstrata de Entes */
class Ente : public Entidade
{
protected:
	// Variaveis
    JogoInfo* jogoInfo;

public:
    // Construtoras e Destrutoras
    Ente(JogoInfo* pji = NULL);
    virtual ~Ente();

    // Metodos de Inicialização
    void iniciarBackground(std::string diretorio);

    // Métodos de Atualização
    virtual void atualizar() = 0;
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;

    // Métodos de Renderização
    virtual void desenhar(sf::RenderTarget& janela) = 0;

};

