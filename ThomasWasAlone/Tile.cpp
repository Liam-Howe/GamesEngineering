#include "stdafx.h"
#include "Tile.h"


Tile::Tile(Point2D pos,float _width,float _height) 
{
	m_Pos = pos;
	m_Size.w = _width;
	m_Size.h = _height;
	Rect *_Rect = new Rect(m_Pos.x, m_Pos.y, m_Size.w, m_Size.h);
	m_Rect.push_back(*_Rect);
}

Tile::~Tile()
{
}

void Tile::Render(Renderer& r) {
	for (int i = 0; i < m_Rect.size(); i++)
	{
		r.drawRect(m_Rect[i], Colour(200, 100, 80));
	}
}


void Tile::Update(unsigned int deltaTime) {

	//float angle = angVel*deltaTime / 1000;
	//Point2D p = rect.pos;//current position

	//					 //apply a rotation about the origin transform
	//rect.pos.x = (float)cos(angle)*p.x - (float)sin(angle)*p.y;
	//rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

}

