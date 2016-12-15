#pragma once
#include "Tile.h"
#include "Compare.h"
#include <queue>
#include <list>
#include <functional>
class Astar {

	

public:

	std::vector<Tile*> astar(int row ,int col, int _gRow,int _gCol, std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	//void calculateSurroundingNodes(Tile* currentNode, std::vector<std::vector<Tile*>>&tiles, int tileAmount,Tile * goalNode);
	 void calculateSurroundingNodes(Tile * currentNode,std::vector<std::vector<Tile*>>&tiles, int tileAmount);
	 int calculateFCost(Tile * n1, Tile * n2);
	void sortByFCost(int f);
private:

};
