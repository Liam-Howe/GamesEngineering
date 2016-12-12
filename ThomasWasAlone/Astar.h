#pragma once
#include "Tile.h"
#include "Compare.h"
#include <queue>
#include <list>
#include <functional>
class Astar {

	

public:

	void astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	//void calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount,Tile * goalNode);
	 void calculateSurroundingNodes(Tile * currentNode,std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	 int calculateFCost(Tile * n1, Tile * n2);
	void sortByFCost(int f);
private:
	std::vector<Tile *> m_openList;
	std::vector<Tile * > m_closedList;
//	std::priority_queue<Tile *, std::vector<Tile*>,Compare> pq;
	int m_mMaxNodes;
	std::vector<Tile*> m_openNodes;
	std::vector<Tile*> m_closedNodes;
	int m_Count; //actual number of nodes in the graph
	std::vector<Tile *> m_path;
	Tile * childNode;


};
