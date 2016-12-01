#include "stdafx.h"
#include "Astar.h"



void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{
	float goalXPos = goalNode->getPosition().x;
	float goalYPos = goalNode->getPosition().y;
	//Tile * currentTile = startNode;
	//m_openNodes.push_back(startNode);
	calculateSurroundingNodes(startNode, tiles, tileAmount, goalNode);
	
	pq.push(startNode);
	
	//while (pq.size() != 0 && pq.top() != goalNode)
	//{
	////	std::list<Tile>::iterator iter = pq.top()->;
	////	std::list<Tile>::iterator endIter = pq.top()->;
	//	for (int i = 0; i < pq.size(); i++)
	//	{
	//	/*	if (pq.)
	//		{

	//		}*/



	//	}
	//	
	//}


	//m_openNodes.push_back(startNode);

	//Tile * currentNode = m_openNodes.at(3);
	//if (m_openNodes.empty() == false)
	//{
	//	for (int i = 0; i < m_openNodes.size(); i++)
	//	{
	//		if (m_openNodes[i] != goalNode)
	//		{
	//			
	//				/*if (m_openNodes.)
	//				{

	//				}*/	
	//		}			
	//	}
	//}
	////take the best node b from the open list
	////if open list is != empty
	//// if b != goal
	////for all surroiunding nodes
	////assign f, g, h values
	////if current node 

}

void Astar::calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount,Tile* endTile)
{
	//calculate surrounding nodes t othe current node
	Point2D currentPosition = currentNode->getPosition();
	for (int col = 0; col < tileAmount; col++)
	{
		for (int row = 0; row < tileAmount; row++)
		{
			if (tiles[row][col] == currentNode)
			{
				if (row != tileAmount -1)
				{
					tiles[row + 1][col]->setGCost(currentNode->getGCost() + 1);
				//	sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
					tiles[row + 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row + 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row + 1][col]->getPosition().x)
						+ (endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)));
					//calculate f vsalues
					tiles[row + 1][col]->setFCost(tiles[row + 1][col]->getGCost() + tiles[row + 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row + 1][col]);
					pq.push(tiles[row + 1][col]);
				}
				if (row !=0)
				{
					tiles[row - 1][col]->setGCost(currentNode->getGCost() + 1);
					tiles[row - 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row - 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row - 1][col]->getPosition().x)
						+ (endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)));
					tiles[row - 1][col]->setFCost(tiles[row - 1][col]->getGCost() + tiles[row - 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row - 1][col]);
					pq.push(tiles[row - 1][col]);
				}	
				if (col != 0)
				{
					tiles[row ][col - 1]->setGCost(currentNode->getGCost() + 1);
					tiles[row ][col - 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row ][col - 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col - 1]->getPosition().x)
						+ (endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)));
					tiles[row ][col - 1]->setFCost(tiles[row ][col - 1]->getGCost() + tiles[row ][col - 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col -1]);
					pq.push(tiles[row ][col - 1]);
				}
				if (col != tileAmount -1)
				{
					tiles[row][col + 1]->setGCost(currentNode->getGCost() + 1);
					tiles[row][col  + 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row][col + 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col + 1]->getPosition().x)
						+ (endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)));
					tiles[row][col + 1]->setFCost(tiles[row][col + 1]->getGCost() + tiles[row][col + 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col + 1]);
					pq.push(tiles[row][col + 1]);
					
				}
			}
		}
	}
}