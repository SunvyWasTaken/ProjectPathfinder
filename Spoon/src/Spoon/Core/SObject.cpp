#include "snpch.h"
#include "SObject.h"
#include "ObjectRender.h"

SObject::SObject()
{
	Render = ObjectRender::Create();
	Render->RenderLocation = &ObjectLocation;
	Render->Init();
}

SObject::~SObject()
{
	delete Render;
}

void SObject::BeginPlay()
{}

void SObject::Tick(float DeltaTime)
{
	
}

FVector2D SObject::GetLocation() const
{
	return ObjectLocation;
}

void SObject::SetLocation(const FVector2D& loc)
{
	ObjectLocation = loc;
}
