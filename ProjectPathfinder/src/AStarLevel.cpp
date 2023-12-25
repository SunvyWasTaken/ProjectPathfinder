#include "AStarLevel.h"
#include "SNode.h"
#include "AStar.h"
#include "PathfinderParam.h"

void AStarLevel::BeginPlay()
{
	// Make a Grid of Square
	std::vector<SNode*> Grid;

	unsigned int Col = GRID_SIZE;
	unsigned int Row = GRID_SIZE;
	int SquareSize = SQSIZE;
	int Padding = PAD;

	for (unsigned int i = 0; i < Row; ++i)
	{
		for (unsigned int j = 0; j < Col; ++j)
		{
			SNode* Carre = SpawnActor<SNode>(FTransform(FVector2D(SquareSize * j, SquareSize * i), FVector2D(SquareSize)));
			Carre->SetLocation(FVector2D(j * SquareSize + Padding * j, i * SquareSize + Padding * i));
			Carre->SetColor(FColor::Blue());
			Carre->SetWalkable(false);
			Carre->bCanDiag = 1;
			Carre->x = j;
			Carre->y = i;
			Grid.push_back(Carre);
#ifdef DEBUG
			std::cout << "A cell is create : " << (i + 1) << std::endl;
#endif // DEBUG

		}
	}
	for (unsigned int i = 0; i < Grid.size() - 1; ++i)
	{
		Grid[i]->AddNeighbour(Grid, Col, Row, i);
#ifdef DEBUG
		std::cout << Grid[i]->x << " " << Grid[i]->y << std::endl;
#endif // DEBUG
	}

	AStar* Algo = SpawnActor<AStar>(FTransform());

	// define the start node and the destination node
	// make sure that it is not a wall
	SNode* Start = Grid[0];
	Start->SetWalkable(true);
	SNode* Destination = Grid[Grid.size() - 1];
	Destination->SetWalkable(true);

	// Put the start and destination node into the algo
	Algo->StartNode = Start;
	Algo->DestinationNode = Destination;
	Algo->OpenList.push_back(Start);

}
