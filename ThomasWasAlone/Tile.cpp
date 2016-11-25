#include "stdafx.h"
#include "Tile.h"


Tile::Tile(Point2D pos,float _width,float _height , tileType tile) 
	: m_Pos(pos) , 
	  m_type(tile)
{
	m_Size.w = _width;
	m_Size.h = _height;
	m_costToTravel = 0;
	_Rect = Rect(m_Pos.x, m_Pos.y, m_Size.w, m_Size.h);
	
	switch (m_type)
	{
	case tileType::START:
		m_col = Colour(200, 45, 300);
		break;
	case tileType::TILE:
		m_costToTravel = 9999;
		m_col = Colour(255, 255, 255);
		break;
	case tileType::WALL:
		m_costToTravel = 0;
		m_col = Colour(100, 100, 100);
		break;
	case tileType::GOAL:
		m_col = Colour(0, 0, 0);
		break;
	}
}

Tile::~Tile()
{
}

void Tile::Render(Renderer& r) {
	switch (m_type)
	{
	case tileType::START:
		r.drawFillRect(_Rect, m_col);
		break;
	case tileType::TILE:
		r.drawRect(_Rect, m_col);
		break;
	case tileType::WALL:
		r.drawFillRect(_Rect, m_col);
		break;
	case tileType::GOAL:
		r.drawFillRect(_Rect, m_col);
		break;
	}

}


void Tile::Update(unsigned int deltaTime) {

	//float angle = angVel*deltaTime / 1000;
	//Point2D p = rect.pos;//current position

	//					 //apply a rotation about the origin transform
	//rect.pos.x = (float)cos(angle)*p.x - (float)sin(angle)*p.y;
	//rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

}

int Tile::getCost()
{
	return m_costToTravel;
}

Point2D Tile::getPosition()
{
	return m_Pos;
}

Rect Tile::getRect()
{
	return _Rect;
}

void Tile::setFCost(int value) 
{
	m_fCost = value;
}

void Tile::setGCost(int value)
{
	m_gCost = value;
}

void Tile::setHCost(int value)
{
	m_hCost = value;
}