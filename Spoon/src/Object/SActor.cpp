#include <snpch.h>
#include "SActor.h"
#include "Spoon/Core/ObjectRender.h"
#include "Spoon/Core/Level.h"

SActor::SActor() : 
	SObject(),
	ObjectColor(255, 255, 255, 255),
	Render(ObjectRender::Create(&ObjectTransform.Location, &ObjectTransform.Size, &ObjectColor)),
	WorldRef(nullptr)
{}

SActor::~SActor()
{
	SetWorldRef(nullptr);
	delete Render;
}

void SActor::BeginPlay()
{
}

void SActor::Tick(float DeltaTime)
{
}

void SActor::DestroyActor()
{
	delete this;
}


void SActor::SetColor(const FColor& color)
{
	ObjectColor = color;
}


void SActor::SetWorldRef(Level* parentRef)
{
	if (WorldRef)
	{
		WorldRef->RemoveObject(this);
	}
	WorldRef = parentRef;
	if (WorldRef)
	{
		WorldRef->AddObject(this);
	}
}
