#pragma once

#include "Utils/JogoInfo.h"
#include "configuracoes.h"
#include "Entities/Entidade.h"

/* Classe abstrata de Entes */
class Ente : public Entidade
{
public:
    // Construtoras e Destrutoras
    Ente();
    virtual ~Ente();

    // Metodos de Inicializa��o
    void iniciarBackground(std::string diretorio);

    // M�todos de Atualiza��o
    virtual void atualizarEventos(sf::Event& evento_sfml) = 0;
};

