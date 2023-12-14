#pragma once
#include "Spoon.h"

#include "GridSquare/GridSquare.h"

class PlayGrid : public SActor
{
public:
    explicit PlayGrid(unsigned int width);
    virtual ~PlayGrid();

    GridSquare& getAt(unsigned int x, unsigned int y) const;
    GridSquare::GridSquareCollection getNeighbors(const GridSquare&) const;

    GridSquare::GridSquareCollection GridSquares;
    unsigned int width;
};

