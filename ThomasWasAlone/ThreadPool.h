#pragma once
#include "SDL_thread.h"
#include <queue>
#include <thread>
#include <functional>
class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();
	void add(std::function<void()>f);
	std::function<void()> consume();
	void createWorkers();
	SDL_sem * getSem();
	SDL_mutex * getLock();
	static ThreadPool* getInstance();
	void remove();
	static int worker(void *ptr);
private:
	int numberOfWorkers;
	SDL_sem * semaphore;
	static ThreadPool * m_instance;
	std::queue<std::function<void()>> _qeue;
	std::vector<SDL_Thread *> m_workers;
	SDL_mutex * _lock;
	SDL_cond * _cond;
};



//inline Worker::Worker()
//{
//
//
//}



