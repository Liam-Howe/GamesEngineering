#pragma once
#include "GameObject.h"
#include "Tile.h"
class NPC : public GameObject
{
public:
	NPC(Point2D _Pos,float _tileWidth ,float _tileHeight, Colour _colour, int row ,int col);
	~NPC();
	void Render(Renderer & r, Point2D _cameraPos);
	void Update(unsigned int deltaTime);
	void updateColour();
	Point2D getPosition();
	int getRow();
	int getCol();
	void setRow(int row);
	void setCol(int col);
	void setPosition(Point2D _pos);
	std::vector<Tile*> getPath();
	void setPath(std::vector<Tile*>);
private:
	Point2D m_Pos;
	Size2D m_Size;
	Rect* m_Rect;
	Colour m_col;
	int m_Row;
	int m_coloumn;
	std::vector<Tile*> m_path;

};

