#include "stdafx.h"
#include "JogoInfo.h"
#include "Ente.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo():
    entes()
{
    this->tamEntidade = 0.f;
    this->tamMapa.x = 0;
    this->tamMapa.y = 0;
    this->janela = NULL;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    this->janela = NULL;
    this->tocaDisco = NULL;
    while (!this->entes.empty())
    {
        delete this->entes.top();
        this->entes.pop();
    }
}

// _______________________________________________________________________________
/* Setters */
void JogoInfo::setTamEntidade(const float te) { this->tamEntidade = te; }

void JogoInfo::setJanela(sf::RenderWindow* j) { this->janela = j; }

void JogoInfo::setTocaDisco(TocaDisco* td) { this->tocaDisco = td; }

void JogoInfo::setTamMapa(unsigned x, unsigned y) { this->tamMapa = sf::Vector2u(x, y); }

// _______________________________________________________________________________
/* Getters */
const sf::Vector2u JogoInfo::getTamMapa() const { return this->tamMapa; }

const float JogoInfo::getTamEntidade() const { return this->tamEntidade; }

TocaDisco* JogoInfo::getTocaDisco() const { return this->tocaDisco; }

const sf::Vector2u JogoInfo::getTamJanela() const { return this->janela->getSize(); }

Ente* JogoInfo::enteTop() { return this->entes.top(); }

// _______________________________________________________________________________
void JogoInfo::pushEnte(Ente* e)
{
    this->entes.push(e);
}

// _______________________________________________________________________________
void JogoInfo::popEnte()
{
    delete this->entes.top();
    this->entes.pop();
}

// _______________________________________________________________________________
void JogoInfo::trocarEnte(Ente* e)
{
    /* Substitui o ente atual pelo novo */
    this->popEnte();
    this->pushEnte(e);
}

// _______________________________________________________________________________
void JogoInfo::fecharJanela() {
    this->janela->close();
}

