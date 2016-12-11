#pragma once
#include "SDL_thread.h"
#include <queue>
#include <thread>
#include <functional>
#include "NPC.h"
class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();
	void addNpc(NPC* npc);
	void addThread();
	SDL_sem * getSem();
	SDL_mutex * getLock();
	static ThreadPool* getInstance();
	NPC * getJob();
	void remove();
	static int worker(void *ptr);

private:
	int numberOfWorkers;
	SDL_sem * semaphore;
	static ThreadPool * m_instance;
	static std::queue<NPC *> _enemyQeue;
	std::vector<SDL_Thread *> m_workers;
	SDL_mutex * _lock;
	SDL_cond * _cond;
};



