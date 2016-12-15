#include "stdafx.h"
#include "Player.h"



Player::Player(Point2D _pos, Size2D _Size, Colour _col,int _row, int _coloumn)
	: m_Pos(_pos), 
      m_Size(_Size),
	m_Col(_col),
	m_Row(_row),
	m_Coloumn(_coloumn)
{
	m_Player =  Rect(Point2D(m_Pos.x,m_Pos.y), Size2D(m_Size.w,m_Size.h));
}

Player::~Player()
{
}

void Player::Render(Renderer& r, Point2D _cameraPos)
{

	r.drawFillRect(Rect(m_Player.pos.x - _cameraPos.x *m_Player.size.w,m_Player.pos.y - _cameraPos.y*m_Player.size.h,m_Player.size.w,m_Player.size.h), m_Col);

}

void Player::move(Point2D dir)
{
	/*if (dir.x == 0 && dir.y == 1)
	{
		
	}
	else if(dir.x == 1 && dir.y == 0)
	{
		m_Player
	}
	else if(dir.x == 0 && dir.y == -1)
	{
		m_Player
	}
	else if(dir.x == -1 && dir.y == 0)
	{
		m_Player
	}*/

}
int  Player::getRow()
{

	return m_Row;
}
int  Player::getCol()
{

	return m_Coloumn;
}

void Player::Update(unsigned int deltaTime) {

	//float angle = angVel*deltaTime / 1000;
	//Point2D p = rect.pos;//current position

	//					 //apply a rotation about the origin transform
	//rect.pos.x = (float)cos(angle)*p.x - (float)sin(angle)*p.y;
	//rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

}
