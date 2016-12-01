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

public:
	Game();
	~Game();
	vector<vector<Tile*>> m_tiles;
	vector<NPC*> m_NPCs;
	bool init();
	void destroy();

	Player* _player;
	void update();
	void render();
	void loop();

	void onEvent(EventListener::Event);
};

