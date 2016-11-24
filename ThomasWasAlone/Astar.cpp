#include "stdafx.h"
#include "Astar.h"



void Astar::astar(Tile *startNode, Tile *goalNode) 
{
	float goalXPos = goalNode->getPosition().x;
	float goalYPos = goalNode->getPosition().y;
	float fn;
	float gn;
	float hn;

	m_openNodes.push_back(startNode);


	for (int i = 0; i < m_mMaxNodes; i++)
	{

	}

}

void Astar::calculateSurroundingNodes(Tile* currentNode) 
{
	//calculate surrounding nodes t othe current node
	Point2D currentPsotion = currentNode->getPosition();
	/*if (currentPsotion - Point2D(0,-1) == )
	{

	}*/

}