
#include "SComposant.h"
#include "Spoon/Core/ObjectRender.h"
#include <snpch.h>

SComposant::SComposant(SComposant* owner) : 
	SObject(),
	Owner(owner),
	Render(ObjectRender::Create((Owner ? Owner : this), &ObjectColor))
{}

SComposant::~SComposant()
{
	delete Render;
}

bool SComposant::RenderComposant(Window* window)
{
	Render->SpoonDraw(window);
	return false;
}

bool const SComposant::IsInBound(const FVector2D& loc) const
{
	const FVector2D halfSize = GetSize();
	const FVector2D minSize = GetLocation() - halfSize;
	const FVector2D maxSize = GetLocation() + halfSize;
	std::cout << "Mouse : " << loc << " -> min : " << minSize << " max : " << maxSize << std::endl;
	const bool bIsInbound = loc <= maxSize && loc >= minSize;
	std::cout << "IsInbound : " << bIsInbound << std::endl;
	return bIsInbound;
}
