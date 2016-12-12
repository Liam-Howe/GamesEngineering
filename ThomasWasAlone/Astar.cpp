#include "stdafx.h"
#include "Astar.h"


void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{
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

	
	Tile * currentNode = startNode;
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
				calculateFCost(m_openList[i], currentNode);
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
		}
	}
}

void Astar::calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{
	//calculate surrounding nodes t othe current node
	Point2D currentPosition = currentNode->getPosition();
	/*for (int col = 0; col < tileAmount; col++)
	{
		for (int row = 0; row < tileAmount; row++)
		{
			if (tiles[row][col] == currentNode)
			{*/
				if (currentNode->getCol() != tileAmount -1)
				{
				//	tiles[row + 1][col]->setGCost(currentNode->getGCost() + 1);
				//	sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
				//	/tiles[row + 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row + 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row + 1][col]->getPosition().x)
					//	+ (endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)));
					//calculate f vsalues
				//	tiles[row + 1][col]->setFCost(tiles[row + 1][col]->getGCost() + tiles[row + 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row + 1][col]);
					if (!(tiles[currentNode->getRow() + 1][currentNode->getCol()]->getMarked()))
					{
						//pq.push(tiles[row + 1][col]);
						m_openList.push_back(tiles[currentNode->getRow() + 1][currentNode->getCol()]);
						//tiles[currentNode->getRow() + 1][currentNode->getCol()]->setMarked(true);
					}				
				}
				if (currentNode->getRow() !=0)
				{
				//	tiles[row - 1][col]->setGCost(currentNode->getGCost() + 1);
					//tiles[row - 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row - 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row - 1][col]->getPosition().x)
					//	+ (endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)));
				//	tiles[row - 1][col]->setFCost(tiles[row - 1][col]->getGCost() + tiles[row - 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row - 1][col]);
					if ((!(tiles[currentNode->getRow() - 1][currentNode->getCol()]->getMarked())))
					{
						m_openList.push_back(tiles[currentNode->getRow() - 1][currentNode->getCol()]);
						//tiles[currentNode->getRow() - 1][currentNode->getCol()]->setMarked(true);
					}		
				}	
				if (currentNode->getCol() != 0)
				{
				//	tiles[row ][col - 1]->setGCost(currentNode->getGCost() + 1);
				//	tiles[row ][col - 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row ][col - 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col - 1]->getPosition().x)
				//		+ (endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)));
				//	tiles[row ][col - 1]->setFCost(tiles[row ][col - 1]->getGCost() + tiles[row ][col - 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col -1]);
					if (!(tiles[currentNode->getRow()][currentNode->getCol() - 1]->getMarked()))
					{
						m_openList.push_back(tiles[currentNode->getRow()][currentNode->getCol() - 1]);
						//tiles[currentNode->getRow()][currentNode->getCol() - 1]->setMarked(true);
					}
				}
				if (currentNode->getCol() != tileAmount -1)
				{
				//	tiles[row][col + 1]->setGCost(currentNode->getGCost() + 1);
				//	tiles[row][col  + 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row][col + 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col + 1]->getPosition().x)
				//		+ (endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)));
				//	tiles[row][col + 1]->setFCost(tiles[row][col + 1]->getGCost() + tiles[row][col + 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col + 1]);
					if (!(tiles[currentNode->getRow()][currentNode->getCol() + 1]->getMarked()))
					{
						m_openList.push_back(tiles[currentNode->getRow()][currentNode->getCol() + 1]);
						//tiles[currentNode->getRow()][currentNode->getCol() + 1]->setMarked(true);
					}
					
			//	}
		//	}
	//	}
	}
}