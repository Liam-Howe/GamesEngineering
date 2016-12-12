#include "stdafx.h"
#include "NPC.h"
#include <iostream>

NPC::NPC(Point2D _Pos,float  _tileWidth,float  _tileHeight, Colour _colour) 
	: m_Pos(_Pos) ,
	m_col(_colour)
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


void NPC::Update(unsigned int deltaTime)
{


}

void NPC::Render(Renderer & r) {
	r.drawFillRect(*m_Rect, m_col);
}
