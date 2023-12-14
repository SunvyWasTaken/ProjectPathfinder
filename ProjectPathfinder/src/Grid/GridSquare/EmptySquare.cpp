#include "EmptySquare.h"

GridSquareCollection EmptySquare::GetNeighbors()
{
    return p_ParentGrid->GetNeighbors(this);
}
