#include "Core/stdafx.h"
#include "Utils/JogoInfo.h"
#include "Entities/Ente.h"

JogoInfo* JogoInfo::_instancia = 0;

JogoInfo* JogoInfo::getInstancia() {
    if (_instancia == 0) {
        _instancia = new JogoInfo();
    }
    
    return _instancia;
}

// _______________________________________________________________________________
JogoInfo::JogoInfo() :
    entes()
{
    this->tocaDisco = new som::TocaDisco();
    this->encerrar = false;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    while (!this->entes.empty())
    {
        delete this->entes.top();
        this->entes.pop();
    }

    delete this->tocaDisco;
    delete this->_instancia;
}

// _______________________________________________________________________________
/* Setters */
void JogoInfo::setEncerrar(const bool e) { this->encerrar = e; }

// _______________________________________________________________________________
/* Getters */
Ente* JogoInfo::enteTop() { return this->entes.top(); }

const bool JogoInfo::getEncerrar() const { return this->encerrar; }

som::TocaDisco* JogoInfo::getTocaDisco() { return this->tocaDisco; }

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
