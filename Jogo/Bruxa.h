#pragma once
#include "Inimigo.h"
#include "GeradorProjeteis.h"
#include "Thread.h"
#define VEL_MAX_BRUXA 1.5
#define VIDA_INICIAL 100
#define DANO_ATAQUE 20
class Bruxa :
    public Inimigo, Thread
{
private:
    // variaveis
    GeradorProjeteis* gerProj;
    sf::Clock tempo_vida;
    sf::Clock cooldown_projetil;
    int tempo_direcao;
    int tempo_cooldown;
    bool vivo;

public:
    // construtoras e destrutoras
    Bruxa();
    Bruxa(sf::Vector2f position, GeradorProjeteis* gp, int tempo_direcao = 50);
    ~Bruxa();
    
    // metodos
    static void executar(Bruxa* bruxa);
    void mover();
    void desenhar(sf::RenderTarget& janela);
    void atualizar();
    void atirar();
    void run();

    int getTipo();
};

