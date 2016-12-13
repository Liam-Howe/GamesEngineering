#pragma once
#include "GameObject.h"

class NPC : public GameObject
{
public:
	NPC(Point2D _Pos,float _tileWidth ,float _tileHeight, Colour _colour, int row ,int col);
	~NPC();
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void updateColour();
	Point2D getPosition();
	int getRow();
	int getCol();
private:
	Point2D m_Pos;
	Size2D m_Size;
	Rect* m_Rect;
	Colour m_col;
	int m_Row;
	int m_coloumn;

};

