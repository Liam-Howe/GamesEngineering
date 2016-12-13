#pragma once
#include "GameObject.h"

class Player : public GameObject
{

public :

	Player(Point2D _pos, Size2D _Size, Colour _col,int _row , int _coloumn);
	~Player();
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void move(Point2D dir);
	int getRow();
	int getCol();

private:
	Point2D m_Pos;
	Size2D m_Size;
	Rect m_Player;
	Colour m_Col;
	int m_Row;
	int m_Coloumn;
};