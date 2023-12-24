#include "Spoon.h"
#include "SNode.h"
#include "AStar.h"

#define GRID_SIZE 250
#define SQSIZE 1
#define PAD 1

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(GRID_SIZE* SQSIZE + (GRID_SIZE *PAD), GRID_SIZE*SQSIZE + (GRID_SIZE *PAD)))
	{}
};

Application* CreateApplication()
{
	return new PathApp();
}


int main()
{
	Application* app = CreateApplication();

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
			SNode* Carre = app->GetWorld()->SpawnActor<SNode>(FTransform(FVector2D(SquareSize * j, SquareSize * i), FVector2D(SquareSize)));
			Carre->SetLocation(FVector2D(j * SquareSize + Padding * j, i * SquareSize + Padding * i));
			Carre->SetColor(FColor::Blue());
			Carre->SetWalkable(false);
			Carre->bCanDiag = false;
			Carre->x = j;
			Carre->y = i;
			Grid.push_back(Carre);
#ifdef DEBUG
			std::cout << "A cell is create : " << (i+1) << std::endl;
#endif // DEBUG

		}
	}
	for (unsigned int i = 0; i < Grid.size() - 1; ++i)
	{
		Grid[i]->AddNeighbour(Grid, Col, Row, i);
#ifdef _DEBUG
		std::cout << Grid[i]->x << " " << Grid[i]->y << std::endl;
#endif // _DEBUG
	}

	AStar* oui = app->GetWorld()->SpawnActor<AStar>(FTransform());
	
	// define the start node and the destination node
	// make sure that it is not a wall
	SNode* Start = Grid[0];
	Start->SetWalkable(true);
	SNode* Destination = Grid[Grid.size() - 1];
	Destination->SetWalkable(true);

	// Put the start and destination node into the algo
	oui->StartNode = Start;
	oui->DestinationNode = Destination;
	oui->OpenList.push_back(Start);

	// TO DO
	// stop le search when path is find
	// faire en sorte que �a fonctionne avec une grille non carr�
	// show number of iteration at the end of the Path
	//faire un video/gif de la recherche de path windows+g


	app->Run();
	delete app;

	return 0;
}

