#include "snpch.h"
#include "SObject.h"
#include "ObjectRender.h"

SObject::SObject()
{
	Render = std::make_unique<ObjectRender>();
}

SObject::~SObject()
{}

void SObject::BeginPlay()
{}

void SObject::Tick(float DeltaTime)
{}

FVector2D SObject::GetLocation() const
{
	return ObjectLocation;
}

void SObject::AddActorLocation(FVector2D& _val)
{
	ObjectLocation += _val;
}