#include "stdafx.h"
#include "Astar.h"



void Astar::astar(Tile *startNode, Tile *goalNode, std::vector<Tile*> &tiles, int tileAmount)
{
	float goalXPos = goalNode->getPosition().x;
	float goalYPos = goalNode->getPosition().y;
	//Tile * currentTile = startNode;
	calculateSurroundingNodes(startNode, tiles, tileAmount, goalNode);
	std::priority_queue<Tile *> pq;
	pq.push(startNode);
	
	//while (pq.size() != 0 && pq.top() != goalNode)
	//{
	//	/*std::list<Tile>::iterator iter = pq.top();
	//	std::list<Tile>::iterator endIter = pq.top()->;*/
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

void Astar::calculateSurroundingNodes(Tile* currentNode, std::vector<Tile*> &tiles, int tileAmount,Tile* endTile)
{
	//calculate surrounding nodes t othe current node
	Point2D currentPosition = currentNode->getPosition();

	for (int i = 0; i < tiles.size(); i++)
	{
			if (tiles[i] == currentNode)
			{
				if (i  > tileAmount)
				{
					tiles[i - tileAmount]->setGCost(currentNode->getGCost()+ 1);
					//sqrt((goalXpos - currXpos)*(goalXpos - currXpos) + (goalYpos - currYpos)*(goalYpos - currYpos));//calcualtes distance to goal from current ie hn
					tiles[i - tileAmount]->setHCost(sqrt((endTile->getPosition().x - tiles[i - tileAmount]->getPosition().x) *(endTile->getPosition().x - tiles[i - tileAmount]->getPosition().x)
				    + (endTile->getPosition().y -tiles[i - tileAmount]->getPosition().y)*(endTile->getPosition().y - tiles[i - tileAmount]->getPosition().y)));
					//calculate f vsalues
					tiles[i - tileAmount]->setFCost(tiles[i - tileAmount]->getGCost() + tiles[i - tileAmount]->getHCost());
					m_openNodes.push_back(tiles[i - tileAmount]);
				}
				if (i < (tileAmount * tileAmount) - tileAmount)
				{
					tiles[i - tileAmount]->setGCost(currentNode->getGCost() + 1);
					tiles[i - tileAmount]->setHCost(sqrt((endTile->getPosition().x - tiles[i + tileAmount]->getPosition().x) *(endTile->getPosition().x - tiles[i + tileAmount]->getPosition().x)
					+ (endTile->getPosition().y - tiles[i + tileAmount]->getPosition().y)*(endTile->getPosition().y - tiles[i + tileAmount]->getPosition().y)));
					tiles[i + tileAmount]->setFCost(tiles[i + tileAmount]->getGCost() + tiles[i + tileAmount]->getHCost());
					m_openNodes.push_back(tiles[i + tileAmount]);				
				}
				if (tiles[i]->getPosition().x > 0)
				{
					tiles[i - tileAmount]->setGCost(currentNode->getGCost() + 1);
					tiles[i - tileAmount]->setHCost(sqrt((endTile->getPosition().x - tiles[i - 1]->getPosition().x) *(endTile->getPosition().x - tiles[i - 1]->getPosition().x)
					+ (endTile->getPosition().y - tiles[i - 1]->getPosition().y)*(endTile->getPosition().y - tiles[i - 1]->getPosition().y)));
					tiles[i - 1]->setFCost(tiles[i - 1]->getGCost() + tiles[i - 1]->getHCost());
					m_openNodes.push_back(tiles[i - 1]);
				}
				if (tiles[i]->getPosition().x < 773)//should be size minus tile width
				{
					tiles[i - tileAmount]->setGCost(currentNode->getGCost() + 1);
					tiles[i - tileAmount]->setHCost(sqrt((endTile->getPosition().x - tiles[i + 1]->getPosition().x) *(endTile->getPosition().x - tiles[i + 1]->getPosition().x)
					+ (endTile->getPosition().y - tiles[i + 1]->getPosition().y)*(endTile->getPosition().y - tiles[i + 1]->getPosition().y)));
					tiles[i + 1]->setFCost(tiles[i + 1]->getGCost() + tiles[i + 1]->getHCost());
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