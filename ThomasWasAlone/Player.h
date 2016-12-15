#pragma once
#include "GameObject.h"
#include "Tile.h"
class Player : public GameObject
{

public :

	Player(Point2D _pos, Size2D _Size, Colour _col,int _row , int _coloumn);
	~Player();
	void Render(Renderer & r, Point2D _cameraPos);
	void Update(unsigned int deltaTime);
	void move(Point2D dir);
	int getRow();
	int getCol();
	void getWayPoints(std::vector<std::vector<Tile*>> &r);
	std::vector<Tile*> wayPoints();
private:
	Point2D m_Pos;
	Size2D m_Size;
	Rect m_Player;
	Colour m_Col;
	int m_Row;
	int m_Coloumn;
	std::vector<Tile*> m_wayPoints;
};