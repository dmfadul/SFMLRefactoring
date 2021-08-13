#include "stdafx.h"
#include "Thread.h"

// _______________________________________________________________________________
Thread::Thread(){}

Thread::~Thread(){}

// _______________________________________________________________________________
void Thread::run(){}

// _______________________________________________________________________________
void Thread::start()
{
	t = std::thread(runThread, this);
}

// _______________________________________________________________________________
void Thread::yield()
{
	std::this_thread::yield();
}

// _______________________________________________________________________________
void Thread::join()
{
	t.join();
}

// _______________________________________________________________________________
void* Thread::runThread(void* pThread)
{
	Thread* sThread = static_cast<Thread*>(pThread);
	if (NULL == sThread)
	{
		std::cout << "thread falhou." << std::endl;
	}
	else
	{
		sThread->run();
	}
	return (void*)NULL;
}
