#pragma once
#include "Tile.h"
class Compare {
public:
	bool operator()(Tile * n1, Tile * n2) {

			return n1->getFCost() > n2->getFCost();

	}
};
