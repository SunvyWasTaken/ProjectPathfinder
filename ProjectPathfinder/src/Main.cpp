#include "Spoon.h"
#include "AStarLevel.h"
#include "PathfinderParam.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(COL* SQSIZE + (COL *PAD), ROW*SQSIZE + (ROW *PAD)))
	{
		SetLevel(new AStarLevel()); 
	}
};

Application* CreateApplication()
{
	return new PathApp();
}


#ifdef DEBUG
int main()
#else
int WinMain()
#endif // DEBUG
{
	Application* app = CreateApplication();
	app->Run();
	delete app;

	return 0;
}


