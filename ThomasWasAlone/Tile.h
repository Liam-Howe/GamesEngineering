#pragma once
#include "BasicTypes.h"
#include "GameObject.h"
#include <vector>
#include "TileType.h"
class Tile: public GameObject {

public :

	Tile(Point2D pos, float _width, float _height, tileType tile,int _gCost, int _fCost,int row,int coloumn);
	~Tile();
	void Render(Renderer & r,Point2D _cameraPos);
	void Update(unsigned int deltaTime);
	Point2D getPosition();
	Rect getRect();
	void setFCost(int value);
	void setGCost(int value);
	void setHCost(int value);
	int getGCost();
	int getHCost();
	int getFCost();
	/*bool getMarked();*/
	void setPrevious(Tile *previous);
	Tile * previous();
	/*void setMarked(bool value);*/
	int getRow();
	int getCol();
	void setColour(Colour _col);
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
	//bool marked;
	int m_row;
	int m_coloumn;
};
