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
	Size2D winSize(800,600);
	int tileAmount = 30;
	float tileCount = tileAmount * tileAmount;
	float tileWidth = winSize.w / tileAmount;
	float tileHeight = winSize.h / tileAmount;
	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize,"Simple SDL App");
	float x = 0;
	float y = 0;
	int tile = 0;

	vector<Tile *> m_temp;
	
	for (int row = 0; row < tileAmount; row++)
	{
		vector<Tile *> m_temp;
		for (int col = 0; col < tileAmount; col++)
		{
			tile = rand() % 1;
			Tile *t = new Tile(Point2D( x,  y), tileWidth, tileHeight, static_cast <tileType>(tile));
			m_temp.push_back(t);
			if (x + tileWidth >= winSize.w)
			{
				y = y + tileHeight;
				x = 0;
				m_tiles.push_back(m_temp);
			}
			else
			{
				x = x + tileWidth;
			}
		}

	}

	int npcCount = 30;
	int tileSpawn = 0;
	
	for (int i = 0; i <= npcCount; i++)
	{
		tileSpawn = rand() % 35 + 405;
		NPC* _temp = new NPC(m_tiles[10][1]->getPosition(), tileWidth, tileHeight,Colour(255,255,255));
		m_NPCs.push_back(_temp);
	}
	 _player = new  Player(Point2D(0, 0), Size2D(tileWidth, tileHeight));
	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);
	Astar _a;

	lastTime = LTimer::gameTime();

	//we want this box to respond to REVERSE event

	//want game loop to pause
	inputManager.AddListener(EventListener::Event::PAUSE, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
	inputManager.AddListener(EventListener::Event::UP, this);
	inputManager.AddListener(EventListener::Event::RIGHT, this);
	inputManager.AddListener(EventListener::Event::DOWN, this);
	inputManager.AddListener(EventListener::Event::LEFT, this);
	_a.astar(m_tiles[0][6], m_tiles[23][3], m_tiles ,tileAmount);
	return true;


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
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->Update(deltaTime);
	}
	
	//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(0,0,0));// prepare for new frame
	
	//render every object
	//for (std::vector<GameObject*>::iterator i = gameObjects.begin(), e= gameObjects.end(); i != e; i++) {
	//	(*i)->Render(renderer);
	//}

	//for (std::vector<Tile*>::iterator i = m_tiles, e = m_tiles->end(); i != e; i++) {
	//	(*i)->Render(renderer);
	//}

	vector< vector<Tile*> >::iterator row;
	vector<Tile*>::iterator col;
	for (row = m_tiles.begin(); row != m_tiles.end(); row++) {
		for (col = row->begin(); col != row->end(); col++) {
		
			(*col)->Render(renderer);
		}
	}



	for (std::vector<NPC*>::iterator i = m_NPCs.begin(), e = m_NPCs.end(); i != e; i++) {
		(*i)->Render(renderer);
	}
	_player->Render(renderer);
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
	
	if (evt == EventListener::Event::QUIT) {
		quit=true;
	}

}
