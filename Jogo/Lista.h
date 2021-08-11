#pragma once
using namespace std;
template<class TIPO>
class Lista
{
public:
	template<class T>
	class Elemento {
	private:
		int id;
		T* pInfo;
		Elemento<T >* pProx;
		Elemento<T >* pAnte;

	public:
		Elemento();
		~Elemento();
		
		void setId(int id);
		const int getId() const;

		void setProximo(Elemento<T >* pp);
		Elemento<T>* getProximo();

		void setAnterior(Elemento<T >* pa);
		Elemento<T>* getAnterior();

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
	bool removerElemento(int id);
	bool incluaInfo(TIPO* pInfo);
	bool listaVazia();

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
	this->pAnte = NULL;
	this->pInfo = NULL;
}

template<class TIPO>
template<class T>
inline Lista<TIPO>::Elemento<T>::~Elemento()
{
	this->pProx = NULL;
	this->pAnte = NULL;
	this->pInfo = NULL;
}

template<class TIPO>
template<class T>
inline void Lista<TIPO>::Elemento<T>::setId(int id) {
	this->id = id;
}

template<class TIPO>
template<class T>
inline const int Lista<TIPO>::Elemento<T>::getId() const
{
	return this->id;;
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
inline void Lista<TIPO>::Elemento<T>::setAnterior(Elemento<T>* pa)
{
	this->pAnte = pa;
}

template<class TIPO>
template<class T>
inline Lista<TIPO>::Elemento<T>* Lista<TIPO>::Elemento<T>::getAnterior()
{
	return this->pAnte;
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
	this->limpaLista();
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
			pElemento->setAnterior(pAtual);
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
inline bool Lista<TIPO>::removerElemento(int id)
{
	Elemento<TIPO>* pElemento = this->pPrimeiro;
	Elemento<TIPO>* pAuxAnt = NULL;		

	while (pElemento != NULL && (pElemento->getId() != id)) {
		pAuxAnt = pElemento;
		pElemento = pElemento->getProximo();
	}

	// Se a lista estiver vazia ou não tiver o elemento
	if (pElemento == NULL)
		return false;

	// Se só tiver um elemento na lista
	else if (pElemento == this->pPrimeiro) {
		this->pPrimeiro = this->pPrimeiro->getProximo();
		if(this->pPrimeiro != NULL)
			this->pPrimeiro->setAnterior(NULL);
	}

	// se o elemento a ser removido é o ultimo da lista
	else if(pElemento->getProximo() == NULL) {
		pElemento->getAnterior()->setProximo(NULL);
		this->pAtual = pElemento->getAnterior();
	}

	// se o elemento a ser removido esta no meio da lista
	else {
		pAuxAnt = pElemento->getAnterior();
		pElemento->getProximo()->setAnterior(pAuxAnt);
		pAuxAnt->setProximo(pElemento->getProximo());
	}
	
	delete(pElemento);
	return true;
}

template<class TIPO>
inline bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
	if (pInfo != NULL)
	{
		Elemento<TIPO>* pElemento = NULL;
		pElemento = new Elemento<TIPO>();
		pElemento->setInfo(pInfo);
		pElemento->setId(pInfo->getId());
		this->incluaElemento(pElemento);
		return true;
	}
	else
	{
		cerr << "Erro, elemento nulo." << endl;
		return false;
	}
}

template<class TIPO>
inline bool Lista<TIPO>::listaVazia()
{
	return (pPrimeiro == NULL) ? true : false;
}

template<class TIPO>
inline Lista<TIPO>::Elemento<TIPO>* Lista<TIPO>::getPrimeiro()
{
	if (this->pPrimeiro == NULL)
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
