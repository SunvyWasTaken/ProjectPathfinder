#pragma once
#include "Spoon.h"

class GridSquare;

class PlayGrid : public SActor
{
public:
    explicit PlayGrid(unsigned int width);
    virtual ~PlayGrid();

    GridSquare& getAt(unsigned int x, unsigned int y) const;
    GridSquareCollection getNeighbors(const GridSquare&) const;

    GridSquareCollection GridSquares;
    unsigned int width;
};

