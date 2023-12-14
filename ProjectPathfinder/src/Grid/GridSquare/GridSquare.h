#pragma once

#include "Spoon.h"

class PlayGrid;
class SNode;

class GridSquare: public SActor
{
public:

	typedef std::vector<GridSquare*> GridSquareCollection;

	GridSquare(): p_ParentGrid(nullptr), p_Node(nullptr) {};
	explicit GridSquare(PlayGrid& grid) : p_ParentGrid(&grid), p_Node(nullptr) {};
	virtual ~GridSquare() = default;

	//virtual GridSquareCollection GetNeighbors() = 0;

	PlayGrid* p_ParentGrid;

	//TODO: use a component
	SNode* p_Node;
};
