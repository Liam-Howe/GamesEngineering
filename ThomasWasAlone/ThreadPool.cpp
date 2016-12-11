#include "stdafx.h"
#include "ThreadPool.h"

ThreadPool * ThreadPool::m_instance = nullptr;
std::queue<NPC*>ThreadPool::_enemyQeue;
ThreadPool::ThreadPool()
	: _lock(SDL_CreateMutex()),
	semaphore(SDL_CreateSemaphore(1)),
	_cond(SDL_CreateCond())
{
}

ThreadPool::~ThreadPool()
{
	
}
ThreadPool * ThreadPool::getInstance()

{
	if (m_instance == nullptr)
	{
		m_instance = new ThreadPool();
	}
	return m_instance;
}

void ThreadPool::add(std::function<void()> f)
{
	SDL_mutexP(_lock);
	//SDL_LockMutex(_lock);
	_qeue.push(f);	
	SDL_mutexV(_lock);
	SDL_SemPost(semaphore);
}
void ThreadPool::addNpc(NPC* npc)
{
	
	SDL_mutexP(_lock);
	_enemyQeue.push(npc);
	SDL_mutexV(_lock);
	//SDL_SemPost(semaphore);
	int i = SDL_SemValue(semaphore);
}
void ThreadPool::remove()
{
	SDL_mutexP(_lock);
	while (_qeue.size() != 0)
	{
		std::function<void()>f = _qeue.front();
		_qeue.pop();
	}
	SDL_mutexV(_lock);
}
std::function<void()> ThreadPool::consume() 
{
	SDL_mutexP(_lock);
	if (_qeue.size() > 0)
	{
		std::function<void()>f = _qeue.front();
		_qeue.pop();
		return f;
	}
	SDL_mutexV(_lock);
	
}
NPC * ThreadPool::consumeJob()
{
	SDL_mutexP(_lock);
	if (_enemyQeue.size() > 0)
	{
	NPC * temp = _enemyQeue.front();
	_enemyQeue.pop();
	return temp;
	}
	SDL_mutexV(_lock);
	
}
void ThreadPool::createWorkers()
{
	 numberOfWorkers = std::thread::hardware_concurrency() - 1;
	//m_pool.push_back(work)
	 for (int  i = 0; i <numberOfWorkers; i++)
	 {
 	    m_workers.push_back(SDL_CreateThread(worker,"t",((void *)NULL)));
		
	 }
	 int p = SDL_SemValue(semaphore);
}

int ThreadPool::worker(void *ptr)
{
	while (true)
	{
		while (_enemyQeue.size() == 0)
		{

		}
		ThreadPool *t = ThreadPool::getInstance();
		SDL_SemWait(t->getSem());
		NPC * npc;
		npc = t->consumeJob();
		SDL_SemPost(t->getSem());
	//	if (npc != NULL)
		//{
			npc->updateColour();
		//}
	}
	return 0;
}
SDL_sem * ThreadPool::getSem() 
{
	return semaphore;
}

SDL_mutex * ThreadPool::getLock()
{
	return _lock;
}
