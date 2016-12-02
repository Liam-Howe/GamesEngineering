#pragma once

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "EventListener.h"
#include "Tile.h"
#include "Player.h"
#include "NPC.h"

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

	SDL_Rect _camera;
	//camera atributes
	const int m_screen_Width = 640;
	const int m_screen_Height = 480;
	const int m_fps = 20;


public:
	Game();
	~Game();
	//tiles
	vector<vector<Tile*>> m_tiles;
	int tile;
	float maxRow;
	float column;
	int tileSpawn;
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
};

