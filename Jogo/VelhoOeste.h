#pragma once
#include "Fase.h"
class VelhoOeste :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    VelhoOeste();
    VelhoOeste(EnteInfo* pei);
    ~VelhoOeste();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderWindow& janela);
};

