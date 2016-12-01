#pragma once
#include "Tile.h"
#include <queue>
#include <list>
class Astar {

	

public:

	void astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	void calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount,Tile * goalNode);

private:

	int m_mMaxNodes;
	std::vector<Tile*> m_openNodes;
	std::vector<Tile*> m_closedNodes;
	int m_Count; //actual number of nodes in the graph
	std::priority_queue<Tile *> pq;


};
