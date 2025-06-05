#include "Core/stdafx.h"
#include "Core/Thread.h"

int Thread::t_id = 0;

Thread::Thread(){}

Thread::~Thread(){}

void Thread::run(){}

void Thread::start()
{
	t_id++;
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

void Thread::detach()
{
	t.detach();
}

void* Thread::runThread(void* pThread)
{
	Thread* sThread = static_cast<Thread*>(pThread);
	int id = sThread->t_id;
	mutex.lock();
	if (NULL == sThread)
	{
		std::cout << "thread falhou." << std::endl;
	}
	else
	{
		if (id == sThread->t_id)
			sThread->run();
	}
	mutex.unlock();
	return (void*)NULL;
}
