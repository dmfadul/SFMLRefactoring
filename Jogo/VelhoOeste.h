#pragma once
#include "NinhoDoDragao.h"
#include "Jogador.h"
#include "TelaMorte.h"

class VelhoOeste :
    public Fase
{
private:

public:
    // Construtoras e Destrutoras
    VelhoOeste(JogoInfo* pji = NULL);
    ~VelhoOeste();

    // Métodos de Atualização
    void atualizar();
    void atualizarEventos(sf::Event& evento_sfml);

    // Métodos de Renderização
    void desenhar(sf::RenderTarget& janela);

};
