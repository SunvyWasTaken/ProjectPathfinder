
#include "SComposant.h"
#include "Spoon/Core/ObjectRender.h"
#include <snpch.h>

SComposant::SComposant() : 
	SObject(), 
	Render(ObjectRender::Create(this, ObjectColor))
{}

SComposant::~SComposant()
{
	delete Render;
}

void SComposant::OnUpdate()
{
	Render->OnUpdate();
}

bool SComposant::RenderComposant(Window* window)
{
	Render->SpoonDraw(window);
	return false;
}

bool const SComposant::IsInBound(const FVector2D& loc) const
{
	const FVector2D halfSize = GetSize()/2;
	return loc.X <= GetLocation().X + halfSize.X && loc.X >= GetLocation().X - halfSize.X && loc.Y <= GetLocation().Y + halfSize.Y && loc.Y >= GetLocation().Y - halfSize.Y;
}
