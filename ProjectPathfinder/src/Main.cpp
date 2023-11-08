#include <iostream>
#include "Spoon/Core/Application.h"
#include "Spoon/Core/SObject.h"
#include "Spoon/Core/Level.h"
#include "Spoon/Library/FMath.h"

int main()
{
	
	auto* app = new Application();
	SObject* Carre = app->GetWorld()->SpawnActor<SObject>(FVector2D(50, 80));
	Carre->SetColor(FColor(255));
	app->Run();
	delete app;

	return 0;
}

