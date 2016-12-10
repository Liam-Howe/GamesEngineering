#include "stdafx.h"
#include "Astar.h"


void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>> &tiles, int tileAmount)
{
	float goalXpos = goalNode->getPosition().x;
	float goalYpos = goalNode->getPosition().y;
	//Tile * currentTile = startNode;
	//m_openNodes.push_back(startNode);
	for (int row = 0; row < tileAmount; row++)
	{
		for (int col = 0; col < tileAmount; col++)
		{
			float currXpos = tiles[row][col]->getPosition().x;
			float currYpos = tiles[row][col]->getPosition().y;
			float distance = sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
			tiles[row][col]->setHCost(distance);
		}
	}
	startNode->setGCost(0);

	pq.push(startNode);
	Tile * childNode = pq.top();
	childNode->setPrevious(NULL);
	childNode->setMarked(true);
	//startNode->setPrevious(startNode);
	//while (pq.size() != 0 && pq.top() != goalNode)
	//{
	//	//std::list<Tile*>::iterator iter = pq.top();
	//	//std::list<Tile*>::iterator endIter = pq.top();
	//	
	//	calculateSurroundingNodes(childNode, tiles, tileAmount, goalNode);
	//	//pq.pop();
	//
	//	   childNode->setPrevious(childNode);
	//	   childNode = pq.top();
	//	   pq.pop();
	//	  
	//		//childNode = pq.top();
	//		if (childNode != pq.top()->previous())
	//		{
	//			int hn = pq.top()->getHCost();
	//			int gn = pq.top()->getGCost() + 1;
	//			int fn = hn + gn;
	//			int childFN = childNode->getGCost() + childNode->getHCost();
	//			//int Gn = pq.top()->getGCost() + childNode->getGCost();
	//			if (fn < childFN)
	//			{
	//				childNode->setPrevious(pq.top());
	//				childNode->setGCost(gn);
	//			}
	//		}

	//	
	//	//pq.pop();
	//}
	
	/*for (Tile * i = goalNode; i->previous() != 0; i = i->previous())
	{
	   pa
	}*/
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
				//	tiles[row + 1][col]->setGCost(currentNode->getGCost() + 1);
				//	sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
				//	/tiles[row + 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row + 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row + 1][col]->getPosition().x)
					//	+ (endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row + 1][col]->getPosition().y)));
					//calculate f vsalues
				//	tiles[row + 1][col]->setFCost(tiles[row + 1][col]->getGCost() + tiles[row + 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row + 1][col]);
					if (!(tiles[row + 1][col]->getMarked()))
					{
						pq.push(tiles[row + 1][col]);
						tiles[row + 1][col]->setMarked(true);
					}				
				}
				if (row !=0)
				{
				//	tiles[row - 1][col]->setGCost(currentNode->getGCost() + 1);
					//tiles[row - 1][col]->setHCost(sqrt((endTile->getPosition().x - tiles[row - 1][col]->getPosition().x) *(endTile->getPosition().x - tiles[row - 1][col]->getPosition().x)
					//	+ (endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)*(endTile->getPosition().y - tiles[row - 1][col]->getPosition().y)));
				//	tiles[row - 1][col]->setFCost(tiles[row - 1][col]->getGCost() + tiles[row - 1][col]->getHCost());
					//m_openNodes.push_back(tiles[row - 1][col]);
					if ((!(tiles[row - 1][col]->getMarked())))
					{
						pq.push(tiles[row - 1][col]);
						tiles[row - 1][col]->setMarked(true);
					}		
				}	
				if (col != 0)
				{
				//	tiles[row ][col - 1]->setGCost(currentNode->getGCost() + 1);
				//	tiles[row ][col - 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row ][col - 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col - 1]->getPosition().x)
				//		+ (endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col - 1]->getPosition().y)));
				//	tiles[row ][col - 1]->setFCost(tiles[row ][col - 1]->getGCost() + tiles[row ][col - 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col -1]);
					if (!(tiles[row][col - 1]->getMarked()))
					{
						pq.push(tiles[row][col - 1]);
						tiles[row][col - 1]->setMarked(true);
					}
				}
				if (col != tileAmount -1)
				{
				//	tiles[row][col + 1]->setGCost(currentNode->getGCost() + 1);
				//	tiles[row][col  + 1]->setHCost(sqrt((endTile->getPosition().x - tiles[row][col + 1]->getPosition().x) *(endTile->getPosition().x - tiles[row][col + 1]->getPosition().x)
				//		+ (endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)*(endTile->getPosition().y - tiles[row][col + 1]->getPosition().y)));
				//	tiles[row][col + 1]->setFCost(tiles[row][col + 1]->getGCost() + tiles[row][col + 1]->getHCost());
					//m_openNodes.push_back(tiles[row][col + 1]);
					if (!(tiles[row][col + 1]->getMarked()))
					{
						pq.push(tiles[row][col + 1]);
						tiles[row][col + 1]->setMarked(true);
					}
					
				}
			}
		}
	}
}