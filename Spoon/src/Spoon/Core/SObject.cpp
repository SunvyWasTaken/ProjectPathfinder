#include "SObject.h"
#include "ObjectRender.h"
#include "Level.h"

SObject::SObject() : ObjectLocation(0, 0), ObjectSize(100, 100), ObjectColor(255, 255, 255, 255), WorldRef(nullptr)
{
	Render = ObjectRender::Create(&ObjectLocation, &ObjectSize, &ObjectColor);
}

SObject::~SObject()
{
	SetWorldRef(nullptr);
	delete Render;
}

void SObject::BeginPlay()
{}

void SObject::Tick(float DeltaTime)
{}

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

void SObject::SetWorldRef(Level* parentRef)
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

void SObject::SetSize(const FVector2D& size)
{
	ObjectSize = size;
}

FVector2D SObject::GetSize() const
{
	return ObjectSize;
}
