#include "snpch.h"
#include "ObjectRender.h"

ObjectRender::ObjectRender(SObject* owner, const FColor& color) : SObject(), Owner(owner), ObjectColor(color)
{
	ObjectTransform = Owner->GetTransform();
}

ObjectRender::~ObjectRender()
{
}
