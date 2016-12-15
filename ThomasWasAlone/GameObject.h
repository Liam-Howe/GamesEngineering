#pragma once

#include "Renderer.h"
#include "math.h"



/*Base class for all in game objects*/
class GameObject
{

public:
	GameObject() {};
	virtual ~GameObject() {};

	virtual void Render(Renderer& r, Point2D _cameraPos)=0;
	virtual void Update(unsigned int deltaTime)=0;


};

