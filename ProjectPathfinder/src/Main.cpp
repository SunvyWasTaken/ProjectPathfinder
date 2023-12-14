#include <iostream>
#include "Spoon.h"

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
	SButton* butt = CreateWidget<SButton>();
	butt->SetColor(FColor(255));
	butt->SetLocation(FVector2D(1280 / 2, 720 / 2));
	app->Run();
	delete app;

	return 0;
}

