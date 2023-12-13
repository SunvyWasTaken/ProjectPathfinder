#include "PlayGrid.h"

#include "EmptySquare.h"

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

GridSquare& PlayGrid::getAt(unsigned int x, unsigned int y) const
{
	assert((x < width && y < width), "Coordinates not in range");
	unsigned int index = x + (width * y);
	return *GridSquares[index];
}
