#pragma once
#include "SDL_thread.h"
#include <queue>
#include <functional>
class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();
	void addjob(std::function<void()>f);
	void consumeJob();
	void spawnWorkers();
	SDL_sem * getSem();
	SDL_mutex * getLock();
	static ThreadPool* getInstance();
private:

	SDL_sem * semaphore;
	static ThreadPool * m_instance;
	std::queue<std::function<void()>> _qeue;

	SDL_mutex * _lock;
	SDL_cond * _cond;
};


