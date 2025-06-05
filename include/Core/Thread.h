#pragma once
#include <thread>
#include <mutex>
class Thread
{
private:
	std::thread t;
	static int t_id;
	static void* runThread(void* pThread);
	virtual void run();
	

public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
	void yield();
	void detach();
};
static std::mutex mutex;
