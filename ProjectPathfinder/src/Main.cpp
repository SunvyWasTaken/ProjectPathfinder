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
	int Col = 20;
	int Row = 20;

	for (unsigned i = 0; i < Row; i++)
	{	
		for (unsigned j = 0; j < Col; j++)
		{
			SNode* Carre = app->GetWorld()->SpawnActor<SNode>(FTransform(FVector2D(21 * j, 21 * i), FVector2D(20)));
			Carre->SetLocation(FVector2D(j * 30 + 10, i * 30 + 10));
			Carre->SetColor(FColor(0, 0, 255, 255));
			Carre->SetWalkable(false);
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

	AStar* oui = app->GetWorld()->SpawnActor<AStar>(FTransform());
	
	SNode* Start = Grid[0];
	Start->SetWalkable(true);
	SNode* Destination = Grid[Grid.size() - 1];
	Destination->SetWalkable(true);

	// stop le search when path is find
	// faire en sorte que ça fonctionne avec une grille non carré
	

	oui->StartNode = Start;
	oui->DestinationNode = Destination;
	oui->OpenList.push_back(Start);


	app->Run();
	delete app;

	return 0;
}

