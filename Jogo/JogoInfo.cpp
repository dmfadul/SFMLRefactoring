#include "stdafx.h"
#include "JogoInfo.h"
#include "Ente.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo() {
    this->tamEntidade = 0.f;
    this->encerrarEnte = false;
    this->janela = NULL;
    this->entes = NULL;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    this->janela = NULL;
    this->entes = NULL;
}

// _______________________________________________________________________________
void JogoInfo::setTamEntidade(const float te)
{
    this->tamEntidade = te;
}

// _______________________________________________________________________________
void JogoInfo::setEncerrarEnte(const bool ee)
{
    this->encerrarEnte = ee;
}

// _______________________________________________________________________________
void JogoInfo::setJanela(sf::RenderWindow* j)
{
    this->janela = j;
}

// _______________________________________________________________________________
void JogoInfo::setEntes(std::stack<Ente* >* e)
{
    this->entes = e;
}

// _______________________________________________________________________________
const float JogoInfo::getTamEntidade() const
{
    return this->tamEntidade;
}

// _______________________________________________________________________________
const bool JogoInfo::getEncerrarEnte() const
{
    return encerrarEnte;
}

// _______________________________________________________________________________
const sf::RenderWindow* JogoInfo::getJanela() const
{
    return this->janela;
}

// _______________________________________________________________________________
const std::stack<Ente*>* JogoInfo::getEntes() const
{
    return this->entes;
}

// _______________________________________________________________________________
void JogoInfo::pushEnte(Ente* e)
{
    this->entes->push(e);
}

// _______________________________________________________________________________
void JogoInfo::fecharJanela() {
    this->janela->close();
}

