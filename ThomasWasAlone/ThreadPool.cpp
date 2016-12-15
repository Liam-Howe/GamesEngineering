#include "stdafx.h"
#include "ThreadPool.h"
#include <iostream>
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
	while (_enemyQeue.size() != 0)
	{
		NPC * temp = _enemyQeue.front();
		_enemyQeue.pop();
	}
	SDL_mutexV(_lock);
}

NPC * ThreadPool::getJob()
{
	//SDL_mutexP(_lock);
	/*if (_enemyQeue.size() > 0)
	{*/
	NPC * temp = _enemyQeue.front();
	_enemyQeue.pop();
	return temp;
	//}
	//SDL_mutexV(_lock);
	
}
void ThreadPool::addThread()
{
	 numberOfWorkers = std::thread::hardware_concurrency() - 1;
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
		NPC * npc =nullptr;
	    npc = t->getJob();
		SDL_SemPost(t->getSem());
		if (npc != NULL)
		{
			Astar a;
			//_a.astar(m_NPCs[i]->getRow(),m_NPCs[i]->getCol(), _player->getRow(),_player->getCol(), m_tiles, tileAmount)
		//	std::cout << "hi" << std::endl;
			npc->setPath(a.astar(npc->getRow(),npc->getCol(), ThreadPool::getInstance()->getPlayer().getRow(), ThreadPool::getInstance()->getPlayer().getCol(), ThreadPool::getInstance()->getTiles(), ThreadPool::getInstance()->getTileAmount()));
		
				//std::vector<Tile*> way = ThreadPool::getInstance()->getPlayer().wayPoints().at(0)->;// ()
			//for (int  i = ThreadPool::getInstance()->getPlayer().wayPoints().size()-1; i >= 0; i--)
			//{
			//	npc->setPath(a.astar(npc->getRow(), npc->getCol(), ThreadPool::getInstance()->getPlayer().wayPoints().at(i)->getRow(), ThreadPool::getInstance()->getPlayer().wayPoints().at(i)->getCol(), ThreadPool::getInstance()->getTiles(), ThreadPool::getInstance()->getTileAmount()));
			//	npc->setRow(ThreadPool::getInstance()->getPlayer().wayPoints().at(i)->getRow());// , ThreadPool::getInstance()->getPlayer().wayPoints().at(i)->getCol())
			//	npc->setCol(ThreadPool::getInstance()->getPlayer().wayPoints().at(i)->getCol());
			//}
		}
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
void ThreadPool::setPlayer(Player * p)
{
	_p = p;

}
void ThreadPool::setAI(std::vector<std::vector<Tile*>>tiles)
{
	_tiles = tiles;

}
Player ThreadPool::getPlayer() 
{
	return *_p;
}
std::vector<std::vector<Tile*>> ThreadPool::getTiles()
{

	return _tiles;
}
void ThreadPool::setTileAmount(int _tileAmount) 
{
	tileAmount = _tileAmount;
}
int ThreadPool::getTileAmount()
{
	return tileAmount;
}