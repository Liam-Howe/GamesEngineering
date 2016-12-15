#pragma once

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "EventListener.h"
#include "Tile.h"
#include "Player.h"
#include "NPC.h"
#include "SDL_thread.h"

using namespace std;
/** The game objct whic manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	Renderer renderer;

	std::vector<GameObject*> gameObjects;
	
	unsigned int lastTime;//time of last update;

	bool pause;
	bool quit;

	
	//camera atributes
	const int m_screen_Width = 640;
	const int m_screen_Height = 480;
	const int m_fps = 20;
	SDL_Thread * thread;
	void test();
	void moveAI();
	
public:
	Game();
	~Game();
	//tiles
	vector<vector<Tile*>> m_tiles;
	int tile;
	float maxRow;
	float column;
	int tileSpawn;
	Rect playerSpawnZone;
	//ai
	vector<NPC*> m_NPCs;
	//player
	Player* _player;
	//camera

	//sdl
	bool init();
	void destroy();
	void update();
	void render();
	void loop();
	int npcCount;
	void onEvent(EventListener::Event);
	void setupPlayerSpawnZone();
	void moveRight();
	void moveUp();
	void moveLeft();
	void moveDown();
private:
	int minX;
	int maxX;
	int minY;
	int maxY;
	int playerSpawnX;
	int playerSpawnY;
	float tileAmount;
	//float tileCount = tileAmount * tileAmount;
	float tileWidth;
	float tileHeight;
	int level;
	Rect* _camera;
	Size2D winSize;
};

