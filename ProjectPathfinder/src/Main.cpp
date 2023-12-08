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
	// Start app
	auto* app = new PathApp();

	// Object exemple
	SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	Carre->SetColor(FColor(255));
	// Object exemple

	app->Run();
	delete app;

	return 0;
}

