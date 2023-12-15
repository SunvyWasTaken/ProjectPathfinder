#include "Spoon.h"
#include "SNode.h"
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
	int SquareSize = 20;
	int Padding = 1;
	int Col = 1280 / SquareSize;
	int Row = 720 / SquareSize;
	

	for (unsigned i = 0; i < Row; i++)
	{	
		for (unsigned j = 0; j < Col; j++)
		{
			SNode* Carre = app->GetWorld()->SpawnActor<SNode>(FTransform(FVector2D(SquareSize * j, SquareSize * i), FVector2D(SquareSize)));
			Carre->SetLocation(FVector2D(j * SquareSize + Padding, i * SquareSize + Padding));
			Carre->SetColor(FColor(0, 0, 255, 255));
			Carre->SetWalkable(false);
			Carre->bCanDiag = 1;
			Carre->x = j;
			Carre->y = i;
			Grid.push_back(Carre);
		}
	}

	int ID = 0;
	for (unsigned i = 0; i < Grid.size() - 1; i++)
	{
		Grid[ID]->AddNeighbour(Grid, Col, Row, ID); 
		//std::cout << Grid[ID]->x << " " << Grid[ID]->y << std::endl;
		ID++;
	}

	AStar* Algo = app->GetWorld()->SpawnActor<AStar>(FTransform());
	
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

	// TO DO														
	// stop le search when path is find								-> ok
	// faire en sorte que ça fonctionne avec une grille non carré	
	// show number of iteration at the end of the Path				-> ok
	//faire un video/gif de la recherche de path windows+g			-> ok


	app->Run();
	delete app;

	return 0;
}

