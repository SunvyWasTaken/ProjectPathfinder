#include "SObject.h"
#include "ObjectRender.h"
#include "Level.h"

SObject::SObject()
{
	Render = ObjectRender::Create();
	Render->RenderLocation = &ObjectLocation;
	Render->ObjectColor = &ObjectColor;
}

SObject::~SObject()
{
	SetParent(nullptr);
	delete Render;
}

void SObject::BeginPlay()
{
	return;
}

void SObject::Tick(float DeltaTime)
{
	return;
}

FVector2D SObject::GetLocation() const
{
	return ObjectLocation;
}

void SObject::SetLocation(const FVector2D& loc)
{
	ObjectLocation = loc;
}

void SObject::DestroyObject()
{
	delete this;
}

void SObject::SetColor(FColor color)
{
	ObjectColor = color;
}

void SObject::SetParent(Level* parentRef)
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
