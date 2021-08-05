#pragma once
#include "Entidade.h"
#include "HitBox.h"
#include "ComponenteMovimento.h"
#define VEL_MAX_PROJETIL 5

class Projetil :
    public Entidade
{
protected:
    sf::Clock tempo_vida;
    HitBox hitbox;
    bool direcao;
    int dano;
    ComponenteMovimento compMov;

public:
    Projetil();
    Projetil(int indice, sf::Vector2f posicao, bool direcao);
    ~Projetil();

    void setPosicao(float x, float y);
    void desenharProjetil(sf::RenderTarget& janela);
    void atualizar();

    void iniciarMovimento();

    void iniciarSprite(int indice);
    void iniciarHitbox(float comprimento, float altura, int off_x, int off_y);
    void iniciarCompMov(float vel_max);
    int getTempoVida();
    int getDano();
    HitBox getHitbox() const;

    
};

