#pragma once
#include "Spoon.h"

#include "GridSquare/GridSquare.h"

class PlayGrid : public SActor
{
public:
    explicit PlayGrid(unsigned int width);
    virtual ~PlayGrid();

    GridSquare& GetAt(unsigned int x, unsigned int y) const;
    GridSquare::GridSquareCollection GetNeighbors(const unsigned int x, const unsigned int y) const;

    GridSquare::GridSquareCollection GridSquares;
    unsigned int width;
};

