#pragma once
#include "SDL_thread.h"
#include <queue>
#include <thread>
#include <functional>
#include "NPC.h"
#include "Player.h"
#include "Tile.h"
#include "Astar.h"
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
	void setPlayer(Player * p);
	void setAI(std::vector<std::vector<Tile*>>tiles);
	Player getPlayer();
	std::vector<std::vector<Tile*>> getTiles();
	void setTileAmount(int tileAmount);
	int getTileAmount();
private:
	int numberOfWorkers;
	SDL_sem * semaphore;
	static ThreadPool * m_instance;
	static std::queue<NPC *> _enemyQeue;
	std::vector<SDL_Thread *> m_workers;
	SDL_mutex * _lock;
	SDL_cond * _cond;
	Player * _p;
	int tileAmount;
	std::vector<std::vector<Tile*>> _tiles;
};



