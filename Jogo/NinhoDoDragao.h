#pragma once
#include "Fase.h"
class NinhoDoDragao :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    NinhoDoDragao();
    NinhoDoDragao(EnteInfo* pei);
    ~NinhoDoDragao();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);

};

