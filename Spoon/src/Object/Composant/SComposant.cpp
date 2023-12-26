
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
	const FVector2D maxSize = GetLocation() + GetSize();

	const bool bIsInbound = loc <= maxSize && loc >= GetLocation();
#ifdef DEBUG
	std::cout << "Mouse : " << loc << " -> min : " << GetLocation() << " max : " << maxSize << std::endl;
	std::cout << "IsInbound : " << bIsInbound << std::endl;
#endif

	return bIsInbound;
}
