#include "snpch.h"
#include "SObject.h"
#include "ObjectRender.h"

SObject::SObject()
{
	Render = ObjectRender::Create();
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

void SObject::AddActorLocation(FVector2D& _val)
{
	ObjectLocation += _val;
}