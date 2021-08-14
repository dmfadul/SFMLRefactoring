#pragma once

#include "JogoInfo.h"
#include "configuracoes.h"
#include "Entidade.h"

/* Classe abstrata de Entes */
class Ente : public Entidade
{
public:
    // Construtoras e Destrutoras
    Ente();
    virtual ~Ente();

    // Metodos de Inicialização
    void iniciarBackground(std::string diretorio);

    // Métodos de Atualização
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;
};

