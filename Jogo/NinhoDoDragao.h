#pragma once
#include "Fase.h"
#include "Cowboy.h"

class NinhoDoDragao :
    public Fase
{
private:
    Mapa mapa;
    Cowboy cowboy;

public:
    // Construtoras e Destrutoras
    NinhoDoDragao(JogoInfo* pji = NULL);
    ~NinhoDoDragao();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);

};

