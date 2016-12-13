#include "stdafx.h"
#include "Astar.h"


void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{
	//float goalXpos = goalNode->getRow();
	//float goalYpos = goalNode->getCol();
	float goalXpos = goalNode->getRow();
	float goalYpos = goalNode->getCol();
	for (int row = 0; row < tileAmount; row++)
	{
		for (int col = 0; col < tileAmount; col++)
		{
			float currXpos = tiles[row][col]->getRow();
			float currYpos = tiles[row][col]->getCol();
			float distance = sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
			tiles[row][col]->setHCost(distance);
		}
	}
	startNode->setGCost(0);
	startNode->setFCost(startNode->getGCost() + startNode->getHCost());

	
	currentNode = startNode;
	childNode = currentNode;
	m_path.push_back(currentNode);
	int f = currentNode->getFCost();
	m_openList.push_back(startNode);
	while (m_openList.size() != 0 && currentNode != goalNode)
	{
		//Tile * currentNode = tiles[currentRow][currentCol]; 
		m_openList.clear();
		m_openList.push_back(currentNode);
		m_closedList.push_back(currentNode);
	
		calculateSurroundingNodes(currentNode, tiles, tileAmount);
		
		for (int i = 0; i < m_openList.size(); i++)
		{
			//if (m_openList[i]->getMarked() == true)
			//{
				m_openList[i]->setGCost(m_openList[i]->getGCost() + 1);
				//calculateFCost(m_openList[i], currentNode);
				currentNode->setFCost(currentNode->getGCost() + currentNode->getHCost());
				m_openList[i]->setFCost(m_openList[i]->getGCost() + m_openList[i]->getHCost());

			//}
		}
		
		sortByFCost(f);
		m_path.push_back(childNode);
		//currentNode->setGCost(childNode->getGCost());
		
		currentNode = childNode;
		
		if (currentNode == goalNode)
		{
			m_closedList.push_back(currentNode);
			m_openList.clear();
		}

	}
	for (int i = 0; i < m_closedList.size(); i++)
	{
		m_closedList[i]->setMarked(true);
	}
}


int Astar::calculateFCost(Tile * n1, Tile * n2)
{
	n1->setFCost(n1->getGCost() + n1->getHCost());
	n2->setFCost(n2->getGCost() + n2->getHCost());
	return n1->getGCost() + n1->getHCost() > n2->getGCost() + n2->getHCost();
	
}



void  Astar::sortByFCost(int f) {
	for (int i = 0; i < m_openList.size(); i++)
	{
		if (m_openList[i]->getFCost() <= f)
		{
			childNode = m_openList.at(i);
			f = m_openList.at(i)->getFCost();
		}
	}
}

void Astar::calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{

	if (currentNode->getCol() < tileAmount -1)
	{
			m_openList.push_back(tiles[currentNode->getCol() + 1][currentNode->getRow()]);
	}
	if (currentNode->getCol() > 0)
	{
			m_openList.push_back(tiles[currentNode->getCol() - 1][currentNode->getRow()]);
	}	
	if (currentNode->getRow() > 0)
	{
			m_openList.push_back(tiles[currentNode->getCol()][currentNode->getRow() - 1]);
	}
	if (currentNode->getRow() < tileAmount -1)
	{
			m_openList.push_back(tiles[currentNode->getCol()][currentNode->getRow() + 1]);
	}
}