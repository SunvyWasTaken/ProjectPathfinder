#include "Spoon.h"
#include "SNode.h"
#include "AStar.h"

#define ROW 250
#define COL 250
#define SQSIZE 1
#define PAD 1

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(COL* SQSIZE + (COL *PAD), ROW*SQSIZE + (ROW *PAD)))
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
  
	unsigned int Col = COL;
	unsigned int Row = ROW;
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
			Carre->bCanDiag = 1;
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

