#pragma once
#include "BasicTypes.h"
#include "GameObject.h"
#include <vector>

class Tile: public GameObject {

public :

	Tile(Point2D pos, float _width, float _height);
	~Tile();
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);


private:
	Rect *_Rect;
	Point2D m_Pos;
	Size2D m_Size;
	std::vector<Rect> m_Rect;


};
