#include "Spoon.h"
#include "AStarLevel.h"
#include "PathfinderParam.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(COl* SQSIZE + (COL *PAD), ROW*SQSIZE + (ROW *PAD)))
	{
		SetLevel(new AStarLevel()); 
	}
};

Application* CreateApplication()
{
	return new PathApp();
}


int main()
{
	Application* app = CreateApplication();
	app->Run();
	delete app;

	return 0;
}

