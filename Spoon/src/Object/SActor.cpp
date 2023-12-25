#include <snpch.h>
#include "SActor.h"
#include "Spoon/Core/Level.h"

SActor::SActor() :
	SObject(),
	ObjectColor(255, 255, 255, 255),
	WorldRef(nullptr)
{}

SActor::~SActor()
{}

void SActor::BeginPlay()
{}

void SActor::Tick(float DeltaTime)
{}

void SActor::DestroyActor()
{
	WorldRef->DestroyActor(this);
}

Level* SActor::GetWorld() const
{
	return WorldRef;
}


void SActor::SetColor(const FColor& color)
{
	ObjectColor = color;
}


void SActor::SetWorldRef(Level* parentRef)
{
	WorldRef = parentRef;
}
