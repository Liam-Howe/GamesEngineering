#include "stdafx.h"
#include "ThreadPool.h"

ThreadPool * ThreadPool::m_instance = nullptr;

ThreadPool::ThreadPool()
	: _lock(SDL_CreateMutex()),
	semaphore(SDL_CreateSemaphore(0)),
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

void ThreadPool::addjob(std::function<void()> f)
{
	_qeue.push(f);	
}
void ThreadPool::consumeJob() 
{



}
void ThreadPool::spawnWorkers()
{
	//int numberOfWorkers = 


}

SDL_sem * ThreadPool::getSem() 
{
	return semaphore;
}

SDL_mutex * ThreadPool::getLock()
{
	return _lock;
}
