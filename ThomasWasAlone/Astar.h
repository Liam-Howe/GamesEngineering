#pragma once
#include "Tile.h"
class Astar {

	

public:

	void astar(Tile *startNode, Tile *goalNode, std::vector<Tile*>&tiles, int tileAmount);
	void calculateSurroundingNodes(Tile* currentNode, std::vector<Tile*>&tiles, int tileAmount);

private:

	int m_mMaxNodes;
	std::vector<Tile*> m_openNodes;
	std::vector<Tile*> m_closedNodes;
	int m_Count; //actual number of nodes in the graph



};
