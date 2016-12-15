#include "stdafx.h"

#include <iostream>
using namespace std;



#include "LTimer.h"
#include "Game.h"
#include "Tile.h"
#include "Player.h"
#include "TileType.h"
#include "NPC.h"
#include "Astar.h"
#include "ThreadPool.h"
#include <functional>
const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
	pause = false;
	quit = false;


}


Game::~Game()
{
}


bool Game::init() {	
	level = 1;
	Size2D winSize1(600, 600);
	Size2D winSize2(800, 800);

	if (level == 1)
	{
		tileAmount = 30;
		winSize = winSize1;
	}
	else if (level == 2)
	{
		tileAmount = 100;
		winSize = winSize2;
	}
	else if (level == 3)
	{
		tileAmount = 1000;
		winSize = winSize2;
	}
	// (600, 600);

	_camera = new Rect(0, 0, winSize.w, winSize.h);
	
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);
	
	
	//ThreadPool *t = ThreadPool::getInstance();
			
	//tiles//tiles//tiles
	
	
	//float tileCount = tileAmount * tileAmount;
	// tileWidth = winSize.w / tileAmount;
	// tileHeight = winSize.h / tileAmount;
	tileWidth = 25;
	tileHeight = 25;
	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize,"Simple SDL App");


	 tile = 0;
	 maxRow = 0;
	 column = 0;
	for (int row = 0; row < tileAmount; row++)
	{
		std::vector<Tile*> temp;

		for (int col = 0; col < tileAmount; col++)
		{
			tile = rand() % 1;
			Tile* t = new Tile(Point2D(0 + (tileWidth*maxRow), 0 + (tileHeight*column)), tileWidth, tileHeight, static_cast<tileType>(tile),0,0,row,col);
			maxRow = maxRow + 1;
			temp.push_back(t);
		}
		if (maxRow >= tileAmount)
		{
			column = column + 1;
			maxRow = 0;
			m_tiles.push_back(temp);
		}
	}
	//updateWalls();

	//ai//ai//ai//ai//ai
	if (level == 1)
	{
		npcCount = 4;
	}
	else if (level == 2)
	{
		npcCount = 49;
	}
	else if (level == 3)
	{
		npcCount = 499;
	}

	 int tileSpawnx = 0;
	
	 if (level ==1)
	 {
		 for (int i = 0; i <= npcCount; i++)
		 {
			 tileSpawnx = 25 + i;
			 
			 NPC* _temp = new NPC(m_tiles[tileSpawnx][tileSpawnx]->getPosition(), tileWidth, tileHeight, Colour(255, 255, 255), tileSpawnx, tileSpawnx);
			 m_NPCs.push_back(_temp);
		 }

	 }
	 else if (level == 2)
	 {
		 int tileSpawny = 70;
		 for (int i = 0; i <= npcCount; i++)
		 {
			 tileSpawn = 10 + i;
			 NPC* _temp = new NPC(m_tiles[tileSpawn][tileSpawny]->getPosition(), tileWidth, tileHeight, Colour(255, 255, 255), tileSpawn, tileSpawny);
			 m_NPCs.push_back(_temp);
		 }

	 }
	 else if (level == 3)
	 {
		 int tileSpawny = 700;
		 for (int i = 0; i <= npcCount; i++)
		 {
			 tileSpawn = 100 + i;
			 NPC* _temp = new NPC(m_tiles[tileSpawn][tileSpawny]->getPosition(), tileWidth, tileHeight, Colour(255, 255, 255), tileSpawn, tileSpawny);
			 m_NPCs.push_back(_temp);
		 }

	 }
	 setupPlayerSpawnZone();
	//_player->getWayPoints(m_tiles);
	// ThreadPool *tp = ThreadPool::getInstance();
	// ThreadPool::getInstance()->setPlayer(_player);
	// ThreadPool::getInstance()->setAI(m_tiles);
	// ThreadPool::getInstance()->setTileAmount(tileAmount);
	////ThreadPool * pool = new ThreadPool();
	//
	// for (int i = 0; i <= npcCount; i++)
	//{
	//	tp->addNpc(m_NPCs[i]);
	//}
	//tp->addThread();
	//
	//set up the viewport
	//we want the vp centred on origin and 20 units wide

	//input//input//input
	lastTime = LTimer::gameTime();
	//we want this box to respond to REVERSE event
	//want game loop to pause
	inputManager.AddListener(EventListener::Event::PAUSE, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
	inputManager.AddListener(EventListener::Event::UP, this);
	inputManager.AddListener(EventListener::Event::RIGHT, this);
	inputManager.AddListener(EventListener::Event::DOWN, this);
	inputManager.AddListener(EventListener::Event::LEFT, this);

	//astar//astar//astar//astar
	Astar _a;
	for (int i = 0; i <= npcCount ; i++)
	{
		m_NPCs[i]->setPath(_a.astar(m_NPCs[i]->getRow(),m_NPCs[i]->getCol(), _player->getRow(),_player->getCol(), m_tiles, tileAmount));	
    }
	
	return true;	
}
void Game::test()
{


}


void Game::setupPlayerSpawnZone() 
{
	minX = 0;
	maxX = 5;
	minY = 10;
	maxY = 15;
	playerSpawnZone = Rect(Point2D(m_tiles[maxY + 1][minX]->getPosition()), Size2D(tileHeight * 6, -tileHeight * 6));
	srand(time(NULL));

	//player//player//player
	playerSpawnX = rand() % (maxY - minY + 1) + minY;
	playerSpawnY = rand() % (maxX - minX + 1) + minX;
	_player = new  Player(m_tiles[playerSpawnX][playerSpawnY]->getPosition(), Size2D(tileWidth, tileHeight), Colour(255, 0, 0),playerSpawnX,playerSpawnY);

}

void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		delete *i;
	}
	gameObjects.clear();
	renderer.destroy();
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update

	//call update on all game objects
	/*for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->Update(deltaTime);
	}*/
	for (int i = 0; i < m_NPCs.size(); i++)
	{
		m_NPCs[i]->Update(deltaTime);
	}
	//moveAI();
	for (int row =0; row < m_tiles.size(); row++) {
		for (int col =0; col != m_tiles.size(); col++) {
		
			m_tiles[row][col]->Update(deltaTime);
		}
	}

	
	//save the curent time for next frame
	lastTime = currentTime;
}
void Game::updateWalls()
{
	if (level ==1)
	{
		for (int row = 0; row < tileAmount; row++)
		{

			for (int col = 0; col < tileAmount; col++)
			{
				if (col == 8 && row == 20)
				{
					m_tiles[row][col]->setMarked(true);
				}
				if (col == 8 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
					
				}
				if (col == 15 && row == 5)
				{
					m_tiles[row][col]->setMarked(true);
				}
				if (col == 15 && row > 5 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
					
				}

				if (col == 22 && row > 15 )
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 22 && row == 15)
				{
					m_tiles[row][col]->setMarked(true);
				}
			}

		}
	}
	else if (level == 2)
	{
		for (int row = 0; row < tileAmount; row++)
		{

			for (int col = 0; col < tileAmount; col++)
			{
				if (col == 20 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 30 && row > 5 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 40 && row > 15)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 50 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 60 && row > 5 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 70 && row > 15)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
			}

		}
	}
	else if (level == 3)
	{
		for (int row = 0; row < tileAmount; row++)
		{

			for (int col = 0; col < tileAmount; col++)
			{
				if (col == 100 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 200 && row > 5 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 300 && row > 15)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 400 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 500 && row > 5 && row < 20)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
				if (col == 600 && row > 15)
				{
					m_tiles[row][col]->setType(tileType::WALL);
				}
			}

		}
	}
	

}

void Game::moveAI()
{
	
}
//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(0,0,0));// prepare for new frame
	//vector< vector<Tile*> >::iterator row;
	//vector<Tile*>::iterator col;
	//for (row = m_tiles.begin(); row != m_tiles.end(); row++) {
	//	for (col = row->begin(); col != row->end(); col++) {
	//	
	//		(*col)->Render(renderer);
	//	}
	//}


	for (int row = _camera->pos.y; row < (_camera->size.h/tileHeight) +_camera->pos.y; row++)
	{
		for (int col = _camera->pos.x; col < (_camera->size.w / tileWidth) +_camera->pos.x; col++)
		{
			m_tiles[row][col]->Render(renderer, _camera->pos);
		}

	}
	
	for (std::vector<NPC*>::iterator i = m_NPCs.begin(), e = m_NPCs.end(); i != e; i++) {
		(*i)->Render(renderer,_camera->pos);
	}
	//renderer.drawRect(Rect(playerSpawnZone), Colour(0, 255, 0));
	_player->Render(renderer, _camera->pos);
	
	
	renderer.present();// display the new frame (swap buffers)	
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate

	int frameNum = 0;
	while (!quit) { //game loop
		capTimer.start();

		inputManager.ProcessInput();

		if(!pause) //in pause mode don't bother updateing
			update();
		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(EventListener::Event evt) {
//	if (evt == EventListener::Event::UP) {
//	/*	_player->move(Point2D(0, 1));
//	}
//	else if (evt == EventListener::Event::RIGHT) {
//		_player->move(Point2D(1,0));
//	}
//	else if (evt == EventListener::Event::DOWN) {
//		_player->move(Point2D(0, -1));
//	}
//	else if (evt == EventListener::Event::LEFT) {
//		_player->move(Point2D(-1, 0));
//	}
//	
//*/

	if (evt == EventListener::Event::PAUSE) {
		pause = !pause;
	}
	
	if (evt == EventListener::Event::UP) {
		moveUp();
	}
	if (evt == EventListener::Event::RIGHT) {
	     moveRight();
	}
	if (evt == EventListener::Event::DOWN) {
		moveDown();
	}
	if (evt == EventListener::Event::LEFT) {
		moveLeft();
	}
	
	if (evt == EventListener::Event::QUIT) {
		quit=true;
	}

}

void Game::moveUp()
{
	if (_camera->pos.y  > 0)
	{
		_camera->pos.y -= 1;
	}	
}
void Game::moveDown()
{
	if (_camera->pos.y < tileAmount - (_camera->size.w / tileHeight))
	{
		_camera->pos.y += 1;
	}
}
void Game::moveRight()
{
	if (_camera->pos.x < tileAmount - (_camera->size.w / tileWidth))
	{
		_camera->pos.x += 1;
	}

}
void Game::moveLeft()
{
	if (_camera->pos.x >0)
	{
		_camera->pos.x -= 1;
	}

}

