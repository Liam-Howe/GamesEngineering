#pragma once
#include "Tile.h"
#include "Compare.h"
#include <queue>
#include <list>
#include <functional>
class Astar {

	

public:

	void astar(Tile *startNode, Tile *goalNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	void calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount,Tile * goalNode);

private:
	std::priority_queue<Tile *, std::vector<Tile*>,Compare> pq;
	int m_mMaxNodes;
	std::vector<Tile*> m_openNodes;
	std::vector<Tile*> m_closedNodes;
	int m_Count; //actual number of nodes in the graph



};
