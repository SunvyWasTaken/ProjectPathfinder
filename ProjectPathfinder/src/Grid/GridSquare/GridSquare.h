#pragma once

#include "Spoon.h"

class PlayGrid;


class GridSquare: public SActor
{
public:

	typedef std::vector<GridSquare*> GridSquareCollection;

	GridSquare(): p_ParentGrid(nullptr) {};
	explicit GridSquare(PlayGrid& grid) : p_ParentGrid(&grid) {};
	virtual ~GridSquare() = default;

	virtual GridSquareCollection GetNeighbors() = 0;

	PlayGrid* p_ParentGrid;
};
