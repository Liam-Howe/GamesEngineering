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
	Point2D getPosition();
	Rect getRect();
	void setFCost(int value);
	void setGCost(int value);
	void setHCost(int value);
	int getGCost();
	int getHCost();
	int getFCost();
	void setPrevious(Tile *previous);
	Tile * previous();
private:
	Rect _Rect;
	Point2D m_Pos;
	Size2D m_Size;
	tileType m_type;
	Colour m_col;
	int m_fCost;
	int m_gCost;
	int m_hCost;
	Tile * m_Previous;
};
