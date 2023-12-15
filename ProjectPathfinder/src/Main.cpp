#include "Spoon.h"
#include "CustomNode.h"
#include "AStar.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(1280, 720))
	{}
};

Application* CreateApplication()
{
	return new PathApp();
}


int main()
{
	auto* app = CreateApplication();

	// Make a Grid of Square
	std::vector<SNode*> Grid;
	unsigned GridPosition = 125;
	unsigned GridSize = 10;
	unsigned SquareSize = 10;
	unsigned Padding = 40;

	for (unsigned i = 0; i < GridSize; i++)
	{	
		for (unsigned j = 0; j < GridSize; j++)
		{
			CustomNode* Node = app->GetWorld()->SpawnActor<CustomNode>(FTransform(FVector2D(SquareSize * j, SquareSize * i), FVector2D(SquareSize)));
			Node->SetLocation(FVector2D(j * (SquareSize + Padding) + GridPosition, i * (SquareSize + Padding) + GridPosition));
			Node->SetColor(FColor::White());
			//Node->SetWalkable(false);
			//Node->bCanDiag = false;
			Node->x = j;
			Node->y = i;
			Grid.push_back(static_cast<SNode*>(Node));
		}
	}

	int ID = 0;
	for (unsigned i = 0; i < Grid.size() - 1; i++)
	{
		Grid[ID]->AddNeighbour(Grid, GridSize, GridSize, ID);
		ID++;
	}

	AStar* oui = app->GetWorld()->SpawnActor<AStar>(FTransform());
	oui->SetLocation(FVector2D(GridPosition, GridPosition));
	
	// define the start node and the destination node
	SNode* Start = Grid[0];
	Start->SetWalkable(true);
	SNode* Destination = Grid[Grid.size() - 1];
	Destination->SetWalkable(true);

	// Put the start and destination node into the algo
	oui->StartNode = Start;
	oui->DestinationNode = Destination;
	oui->OpenList.push_back(Start);

	app->Run();
	delete app;

	return 0;
}

