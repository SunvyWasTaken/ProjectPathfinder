#pragma once

#include "Spoon.h"

typedef std::vector<GridSquare*> GridSquareCollection;
class PlayGrid;

class SPOON_API GridSquare: public SObject
{
public:
	GridSquare(): p_ParentGrid(nullptr) {};
	explicit GridSquare(PlayGrid& grid) : p_ParentGrid(&grid) {};
	virtual ~GridSquare() = default;

	virtual GridSquareCollection GetNeighbors() = 0;

	PlayGrid* p_ParentGrid;
};

