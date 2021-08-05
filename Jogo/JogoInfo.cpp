#include "stdafx.h"
#include "JogoInfo.h"
#include "Tela.h"

// _______________________________________________________________________________
JogoInfo::JogoInfo() :
    telas()
{
    this->tocaDisco = new TocaDisco();
    this->encerrar = false;
}

// _______________________________________________________________________________
JogoInfo::~JogoInfo()
{
    while (!this->telas.empty())
    {
        delete this->telas.top();
        this->telas.pop();
    }

    delete this->tocaDisco;
}

// _______________________________________________________________________________
/* Setters */
void JogoInfo::setEncerrar(const bool e) { this->encerrar = e; }

// _______________________________________________________________________________
/* Getters */
Tela* JogoInfo::telaTop() { return this->telas.top(); }

const bool JogoInfo::getEncerrar() const { return this->encerrar; }

TocaDisco* JogoInfo::getTocaDisco() { return this->tocaDisco; }

// _______________________________________________________________________________
void JogoInfo::pushTela(Tela* e)
{
    this->telas.push(e);
}

// _______________________________________________________________________________
void JogoInfo::popTela()
{
    delete this->telas.top();
    this->telas.pop();
}

// _______________________________________________________________________________
void JogoInfo::trocarTela(Tela* e)
{
    /* Substitui o ente atual pelo novo */
    this->popTela();
    this->pushTela(e);
}
