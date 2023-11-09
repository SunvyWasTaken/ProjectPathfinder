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
	SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	Carre->SetColor(FColor(255));
	app->Run();
	delete app;

	return 0;
}

