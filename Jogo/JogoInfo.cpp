#include "stdafx.h"
#include "JogoInfo.h"
#include "Ente.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo() {
    this->tamEntidade = 0.f;
    this->tamMapaX = 0;
    this->tamMapaY = 0;
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
void JogoInfo::setTamEntidade(const float te) { this->tamEntidade = te; }

void JogoInfo::setEncerrarEnte(const bool ee) { this->encerrarEnte = ee; }

void JogoInfo::setJanela(sf::RenderWindow* j) { this->janela = j; }

void JogoInfo::setEntes(std::stack<Ente* >* e) { this->entes = e; }

void JogoInfo::setTamMapaX(const unsigned int tx) { this->tamMapaX = tx; }

void JogoInfo::setTamMapaY(const unsigned int ty) { this->tamMapaY = ty; }

// _______________________________________________________________________________
const unsigned int JogoInfo::getTamMapaX() const { return this->tamMapaX; }

const unsigned int JogoInfo::getTamMapaY() const { return this->tamMapaY; }

const float JogoInfo::getTamEntidade() const { return this->tamEntidade; }

const bool JogoInfo::getEncerrarEnte() const { return this->encerrarEnte; }

const sf::RenderWindow* JogoInfo::getJanela() const { return this->janela; }

const std::stack<Ente*>* JogoInfo::getEntes() const { return this->entes;}

// _______________________________________________________________________________
void JogoInfo::pushEnte(Ente* e)
{
    this->entes->push(e);
}

// _______________________________________________________________________________
void JogoInfo::fecharJanela() {
    this->janela->close();
}

