#pragma once
#include "GridSquare.h"
class EmptySquare final :
    public GridSquare
{
public:
    EmptySquare() : visitedCount(0), GridSquare() {};
    EmptySquare(PlayGrid& grid) : visitedCount(0), GridSquare(grid) {};

    GridSquare::GridSquareCollection GetNeighbors() override;

    unsigned int visitedCount;
};

