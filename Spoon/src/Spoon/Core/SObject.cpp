#include "snpch.h"
#include "SObject.h"
#include "ObjectRender.h"

SObject::SObject()
{
	Render = ObjectRender::Create();
	Render->RenderLocation = &ObjectLocation;
	Render->ObjectColor = &ObjectColor;
}

SObject::~SObject()
{
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

void SObject::SetColor(FColor color)
{
	ObjectColor = color;
}
