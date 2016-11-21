#include "stdafx.h"
#include "Player.h"



Player::Player(Point2D _pos, Size2D _Size) 
	: m_Pos(_pos), 
      m_Size(_Size)
{
	m_Player = new Rect(Point2D(m_Pos.x,m_Pos.y), Size2D(m_Size.w,m_Size.h));
}

Player::~Player()
{
}

void Player::Render(Renderer& r) {

	r.drawFillRect(*m_Player, Colour(100, 50, 180));

}


void Player::Update(unsigned int deltaTime) {

	//float angle = angVel*deltaTime / 1000;
	//Point2D p = rect.pos;//current position

	//					 //apply a rotation about the origin transform
	//rect.pos.x = (float)cos(angle)*p.x - (float)sin(angle)*p.y;
	//rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

}
