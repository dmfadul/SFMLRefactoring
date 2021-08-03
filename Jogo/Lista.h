#pragma once
using namespace std;
template<class TIPO>
class Lista
{
public:
	template<class T>
	class Elemento {
	private:
		T* pInfo;
		Elemento<T >* pProx;

	public:
		Elemento();
		~Elemento();
		
		void setProximo(Elemento<T >* pp);
		Elemento<T>* getProximo();

		void setInfo(T* pi);
		T* getInfo();
	};

private:
	Elemento<TIPO>* pPrimeiro;
	Elemento<TIPO>* pAtual;
public:
	Lista();
	~Lista();
	void inicializa();
	bool incluaElemento(Elemento<TIPO>* pElemento);
	bool incluaInfo(TIPO* pInfo);

	Elemento<TIPO>* getPrimeiro();
	Elemento<TIPO>* getAtual();

	void setPrimeiro(Elemento<TIPO>* pp);
	void setAtual(Elemento<TIPO>* pa);

	void limpaLista();
};

// _______________________________________________________________________________
/* CLASSE ELEMENTO */
template<class TIPO>
template<class T>
inline Lista<TIPO>::Elemento<T>::Elemento()
{
	this->pProx = NULL;
	this->pInfo = NULL;
}

template<class TIPO>
template<class T>
inline Lista<TIPO>::Elemento<T>::~Elemento()
{
	this->pProx = NULL;
	this->pInfo = NULL;
}

template<class TIPO>
template<class T>
inline void Lista<TIPO>::Elemento<T>::setProximo(Elemento<T>* pp)
{
	this->pProx = pp;
}

template<class TIPO>
template<class T>
inline Lista<TIPO>::Elemento<T>* Lista<TIPO>::Elemento<T>::getProximo()
{
	return this->pProx;
}

template<class TIPO>
template<class T>
inline void Lista<TIPO>::Elemento<T>::setInfo(T* pi)
{
	this->pInfo = pi;
}

template<class TIPO>
template<class T>
inline T* Lista<TIPO>::Elemento<T>::getInfo()
{
	return this->pInfo;
}

// _______________________________________________________________________________
/* CLASSE LISTA */

template<class TIPO>
inline Lista<TIPO>::Lista()
{
	this->inicializa();
}

template<class TIPO>
inline Lista<TIPO>::~Lista()
{
	delete this->pPrimeiro;
	delete this->pAtual;
}

template<class TIPO>
inline void Lista<TIPO>::inicializa()
{
	pPrimeiro = NULL;
	pAtual = NULL;
}

template<class TIPO>
inline bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
	if (pElemento != NULL)
	{
		if (pPrimeiro == NULL)
		{
			pPrimeiro = pElemento;
			pAtual = pElemento;
		}
		else
		{
			pAtual->setProximo(pElemento);
			pAtual = pAtual->getProximo();
		}
		return true;
	}
	else
	{
		cout << "Erro, elemento nulo na lista" << endl;
		return false;
	}
}

template<class TIPO>
inline bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
	if (pInfo != NULL)
	{
		Elemento<TIPO>* pElemento = NULL;
		pElemento = new Elemento<TIPO>();
		pElemento->setInfo(pInfo);
		this->incluaElemento(pElemento);
		return true;
	}
	else
	{
		cout << "Erro, elemento nulo." << endl;
		return false;
	}
}

template<class TIPO>
inline Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
	if (this == NULL)
		return NULL;
	return this->pPrimeiro;
}

template<class TIPO>
inline Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getAtual()
{
	return this->pAtual;
}

template<class TIPO>
inline void Lista<TIPO>::setPrimeiro(Elemento<TIPO>* pp)
{
	this->pPrimeiro = pp;
}

template<class TIPO>
inline void Lista<TIPO>::setAtual(Elemento<TIPO>* pa)
{
	this->pAtual = pa;
}

template<class TIPO>
inline void Lista<TIPO>::limpaLista()
{
	Elemento<TIPO>* paux1, * paux2;

	paux1 = this->getPrimeiro();
	paux2 = paux1;

	while (paux1 != NULL)
	{
		paux2 = paux1->getProximo();
		delete (paux1);
		paux1 = paux2;
	}

	this->setPrimeiro(NULL);
	this->setAtual(NULL);
}
