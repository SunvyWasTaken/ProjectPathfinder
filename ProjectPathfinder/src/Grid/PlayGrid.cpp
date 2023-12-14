#include "PlayGrid.h"

#include "Grid/GridSquare/EmptySquare.h"

PlayGrid::PlayGrid(unsigned int width): width(width)
{
	for (size_t i = 0; i < width*width; i++)
	{
		GridSquares.push_back(new EmptySquare(*this));
	}
}
 
PlayGrid::~PlayGrid()
{
	for (size_t i = 0; i < width*width; i++)
	{
		delete GridSquares[i];
	}
}

GridSquare& PlayGrid::GetAt(unsigned int x, unsigned int y) const
{
	assert((x < width && y < width), "Coordinates not in range");
	unsigned int index = x + (width * y);
	return *GridSquares[index];
}

GridSquare::GridSquareCollection PlayGrid::GetNeighbors(const unsigned int x, const unsigned int y) const
{
	GridSquare::GridSquareCollection temp;

	if(x+1 < width)
		temp.push_back(&GetAt(x + 1, y));
	if(x > 0)
		temp.push_back(&GetAt(x - 1, y));
	if(y+1 < width)
		temp.push_back(&GetAt(x, y + 1));
	if (y > 0)
		temp.push_back(&GetAt(x, y - 1));

	return temp;
}
