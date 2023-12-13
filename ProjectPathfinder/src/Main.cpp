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
	app->Run();
	delete app;

	return 0;
}

