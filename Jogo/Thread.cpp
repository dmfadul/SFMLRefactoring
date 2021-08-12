#include "stdafx.h"
#include "Thread.h"

Thread::Thread(){}

Thread::~Thread(){}

void Thread::run(){}

void Thread::start()
{
	t = std::thread(runThread, this);
}

void Thread::yield()
{
	std::this_thread::yield();
}

void Thread::join()
{
	t.join();
}

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
