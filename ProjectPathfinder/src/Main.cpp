#include <iostream>
#include "Spoon/Core/Application.h"
#include "Spoon/Core/SObject.h"
#include "Spoon/Core/Level.h"

int main()
{
	
	auto* app = new Application();
	app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	app->Run();
	delete app;

	return 0;
}

