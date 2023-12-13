#pragma once
#include "Spoon.h"

class GridSquare;

class SPOON_API PlayGrid : public SObject
{
public:
    explicit PlayGrid(unsigned int width);
    virtual ~PlayGrid();

    GridSquare& getAt(unsigned int x, unsigned int y) const;
    GridSquareCollection getNeighbors(const GridSquare&) const;

    GridSquareCollection GridSquares;
    unsigned int width;
};

