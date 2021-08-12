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
    std::string atirador;
    ComponenteMovimento compMov;

public:
    Projetil();
    Projetil(sf::Vector2f posicao, bool direcao, std::string img, float escalax, float escalay);
    ~Projetil();

    // metodos de inicilização
    void iniciarMovimento();
    void iniciarSprite(std::string imgCaminho, float scale_x, float scale_y);
    void iniciarHitbox(float comprimento, float altura, int off_x, int off_y);
    void iniciarCompMov(float vel_max);

    // setters e getters
    void setPosicao(float x, float y);
    int getTempoVida();
    int getDano();
    sf::Vector2f getPosicao();
    const bool getDirecao() const;
    const std::string getAtirador() const;
    HitBox getHitbox() const;

    // metodos
    void desenhar(sf::RenderTarget& janela);
    void atualizar();

    
};

