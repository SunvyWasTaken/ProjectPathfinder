#include "snpch.h"
#include "ObjectRender.h"

ObjectRender::ObjectRender(FVector2D* loc, FVector2D* size, FColor* color) : RenderLocation(loc), ObjectSize(size), ObjectColor(color)
{
}

ObjectRender::~ObjectRender()
{
}
