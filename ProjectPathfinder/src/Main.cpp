#include <iostream>
#include "Spoon.h"
#include "SNode.h"
#include "AStar.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(1280, 720))
	{

	}
};

Application* CreateApplication()
{
	return new PathApp();
}


int main()
{
	auto* app = CreateApplication();

	//SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	//Carre->SetColor(FColor(255));
	

	// Make a Grid of Square
	std::vector<SNode*> Grid;
	int Col = 10;
	int Row = 10;

	for (unsigned i = 0; i < Col; i++)
	{	
		for (unsigned j = 0; j < Row; j++)
		{
			SNode* Carre = app->GetWorld()->SpawnActor<SNode>(FTransform(FVector2D(50 * j, 50 * i), FVector2D(20))); // change the 15 by square size + padding
			Carre->SetColor(FColor(0,0,255,255)); // RGBA for blue
			Carre->SetLocation(FVector2D(j * 50, i * 50));
			Grid.push_back(Carre);
			
		}
	}
	int ID = 0;


	for (unsigned i = 0; i < Grid.size() - 1; i++)
	{
		Grid[ID]->AddNeighbour(Grid, ID); 
		ID++;
	}

	AStar* oui = app->GetWorld()->SpawnActor<AStar>(FTransform());
	
	SNode* Start = Grid[0];
	SNode* Destination = Grid[15];

	

	oui->StartNode = Start;
	oui->DestinationNode = Destination;
	oui->OpenList.push_back(Start);


	app->Run();
	delete app;

	return 0;
}

