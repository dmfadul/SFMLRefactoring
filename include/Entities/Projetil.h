#pragma once
#include "Entities/Entidade.h"
#include "Utils/HitBox.h"
#include "Core/ComponenteMovimento.h"
#define VEL_MAX_PROJETIL 5

class Projetil :
    public Entidade
{
protected:
    // variaveis
    sf::Clock tempo_vida;
    HitBox hitbox;
    bool direcao;
    int dano;
    std::string atirador;
    ComponenteMovimento compMov;

public:
    // construtoras e destrutoras
    Projetil();
    Projetil(sf::Vector2f posicao, bool direcao, std::string img, float escalax, float escalay);
    ~Projetil();

    // metodos de iniciliza��o
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

