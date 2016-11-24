#pragma once
#include "BasicTypes.h"
#include "GameObject.h"
#include <vector>
#include "TileType.h"
class Tile: public GameObject {

public :

	Tile(Point2D pos, float _width, float _height, tileType tile);
	~Tile();
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	int getCost();
	Point2D getPosition();

private:
	Rect *_Rect;
	Point2D m_Pos;
	Size2D m_Size;
	std::vector<Rect> m_Rect;
	tileType m_type;
	Colour m_col;
	int m_costToTravel;
};
