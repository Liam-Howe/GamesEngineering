#include "stdafx.h"
#include "Astar.h"



void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<Tile*> &tiles, int tileAmount)
{
	float goalXPos = goalNode->getPosition().x;
	float goalYPos = goalNode->getPosition().y;
	float fn;
	float gn;
	float hn;

	m_openNodes.push_back(startNode);
	calculateSurroundingNodes(startNode, tiles,tileAmount);

	for (int i = 0; i < m_mMaxNodes; i++)
	{
		
	}

}

void Astar::calculateSurroundingNodes(Tile* currentNode, std::vector<Tile*> &tiles, int tileAmount)
{
	//calculate surrounding nodes t othe current node
	Point2D currentPosition = currentNode->getPosition();

	for (int i = 0; i < tiles.size(); i++)
	{
			if (tiles[i] == currentNode)
			{
				if (i  > tileAmount)
				{
					m_openNodes.push_back(tiles[i - tileAmount]);
				}
				if (i < (tileAmount * tileAmount) - tileAmount)
				{
					m_openNodes.push_back(tiles[i + tileAmount]);				
				}
				if (tiles[i]->getPosition().x > 0)
				{
					m_openNodes.push_back(tiles[i - 1]);
				}
				if (tiles[i]->getPosition().x < 773)
				{
					m_openNodes.push_back(tiles[i + 1]);
				}				
			}
	}
		
		/*if (currentPosition.x == tiles[i]->getPosition().x && tiles[i]->getPosition().y == currentPosition.y + currentNode->getRect().size.h)
		{
			m_openNodes.push_back(tiles[i]);
		}
		else if (tiles[i]->getPosition().y == currentPosition.x +currentNode->getRect().size.w && tiles[i]->getPosition().y == currentPosition.y)
		{
			m_openNodes.push_back(tiles[i]);
			*/

}