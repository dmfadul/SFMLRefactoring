#include "stdafx.h"
#include "JogoInfo.h"
#include "Ente.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo() :
    entes()
{
    this->tocaDisco = new TocaDisco();
    this->encerrar = false;
    this->view = NULL;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    while (!this->entes.empty())
    {
        delete this->entes.top();
        this->entes.pop();
    }
}

// _______________________________________________________________________________
/* Setters */
void JogoInfo::setEncerrar(const bool e) { this->encerrar = e; }

// _______________________________________________________________________________
/* Getters */
Ente* JogoInfo::enteTop() { return this->entes.top(); }

const bool JogoInfo::getEncerrar() const { return this->encerrar; }

TocaDisco* JogoInfo::getTocaDisco() const { return this->tocaDisco; }

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
