#include <iostream>
#include "Spoon.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(1280, 720))
	{}
};


int main()
{
	auto* app = new PathApp();

	//SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	//Carre->SetColor(FColor(255));
	

	// Make a Grid of Square
	for (unsigned i = 0; i < 10; i++)
	{	
		for (unsigned j = 0; j < 10; j++)
		{
			SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50 + 15 * i, 80 + 15 * j)); // change the 15 by square size + padding
			Carre->SetColor(FColor(255,0,0,255)); // RGBA for red
		}
	}

	
	
	app->Run();
	delete app;

	return 0;
}

