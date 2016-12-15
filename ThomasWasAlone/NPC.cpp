#include "stdafx.h"
#include "NPC.h"
#include <iostream>

NPC::NPC(Point2D _Pos,float  _tileWidth,float  _tileHeight, Colour _colour, int row, int col) 
	: m_Pos(_Pos) ,
	m_col(_colour),
	m_Row(row),
	m_coloumn(col)
{
	m_Size.w = _tileWidth;
	m_Size.h = _tileHeight;
	m_Rect = new Rect(Point2D(m_Pos.x, m_Pos.y), Size2D(m_Size.w, m_Size.h));

}

NPC::~NPC()
{
}
//int i = 0;
void NPC::updateColour()
{
	
	//i++;
	std::cout << "hi";// << i;
	m_col = Colour(100, 20, 0);
}

void NPC::setRow(int _row)
{

	m_Row = _row;
}
void NPC::setCol(int _col)
{

	m_coloumn = _col;
}
void NPC::Update(unsigned int deltaTime)
{
	

}

Point2D NPC::getPosition()
{

	return m_Pos;
}

void NPC::Render(Renderer & r, Point2D _cameraPos)
{
	r.drawFillRect(Rect(m_Rect->pos.x - _cameraPos.x *m_Rect->size.w, m_Rect->pos.y - _cameraPos.y*m_Rect->size.h, m_Rect->size.w, m_Rect->size.h), m_col);
}
int NPC::getPathPos()
{

	return pathpos;
}
void NPC::setPathPos(int val)
{

	pathpos = pathpos + val;
}
int NPC::getRow()
{
	return m_Row;
}
int NPC::getCol() 
{
	return m_coloumn;
}
void NPC::setPath(std::vector<Tile*>p) 
{
	m_path = p;
}

std::vector<Tile*> NPC::getPath()
{
	return m_path;
}
void NPC::setPosition(Point2D _pos) 
{
	m_Rect->pos.x = _pos.x;
	m_Rect->pos.y = _pos.y;
	//m_Pos = _pos;
}


