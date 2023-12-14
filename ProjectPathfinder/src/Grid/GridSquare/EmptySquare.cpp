#include "EmptySquare.h"

GridSquare::GridSquareCollection EmptySquare::GetNeighbors()
{
    return p_ParentGrid->GetNeighbors(this);
}
