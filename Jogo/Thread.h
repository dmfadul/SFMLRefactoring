#pragma once
#include <thread>
class Thread
{
private:
	std::thread t;
	static void* runThread(void* pThread);
	virtual void run();

public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	void yield();
};

