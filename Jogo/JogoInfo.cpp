#include "stdafx.h"
#include "JogoInfo.h"
#include "Ente.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo():
    entes()
{
    this->tamEntidade = 0.f;
    this->tamMapaX = 0;
    this->tamMapaY = 0;
    this->janela = NULL;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    this->janela = NULL;
    while (!this->entes.empty())
    {
        delete this->entes.top();
        this->entes.pop();
    }
}

// _______________________________________________________________________________
void JogoInfo::setTamEntidade(const float te) { this->tamEntidade = te; }

void JogoInfo::setJanela(sf::RenderWindow* j) { this->janela = j; }

void JogoInfo::setTamMapaX(const unsigned int tx) { this->tamMapaX = tx; }

void JogoInfo::setTamMapaY(const unsigned int ty) { this->tamMapaY = ty; }

// _______________________________________________________________________________
const unsigned int JogoInfo::getTamMapaX() const { return this->tamMapaX; }

const unsigned int JogoInfo::getTamMapaY() const { return this->tamMapaY; }

const float JogoInfo::getTamEntidade() const { return this->tamEntidade; }

const sf::RenderWindow* JogoInfo::getJanela() const { return this->janela; }

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

