#pragma once
#include "Inimigo.h"
#include <thread>
#define VEL_MAX_BRUXA 1.5
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20
class Bruxa :
    public Inimigo
{
private:
    // variaveis
    sf::Clock tempo_vida;
    int tempo_direcao;  
    std::thread t;
    bool vivo;


public:
    // construtoras e destrutoras
    Bruxa();
    Bruxa(sf::Vector2f position, int tempo_direcao = 50);
    ~Bruxa();
    
    // metodos
    static void executar(Bruxa* bruxa);
    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();

    int getTipo();

};

