#pragma once
#include "GridSquare.h"
class ObstacleSquare :
    public GridSquare
{
    ObstacleSquare() = default;
    explicit ObstacleSquare(PlayGrid& grid) : GridSquare(grid) {};
};

