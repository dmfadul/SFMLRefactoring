#pragma once
#include <thread>
/* Classe que gerencia todas as threads do jogo */
class Thread
{
private:
	// variaveis
	std::thread t;
	static void* runThread(void* pThread);
	virtual void run();

public:
	// construtoras e destrutoras
	Thread();
	virtual ~Thread();

	// metodos
	void start();
	void join();
	void yield();
};

