#include "snpch.h"
#include "SfmlObject.h"
#include "TextureMgr.h"
#include "SfmlWindow.h"
#include "Spoon/Library/FMath.h"

ObjectRender* ObjectRender::Create(FVector2D* loc, FVector2D* size, FColor* color)
{
	return new SfmlRender(loc, size, color);
}

SfmlRender::SfmlRender(FVector2D* loc, FVector2D* size, FColor* color) : ObjectRender(loc, size, color), shape(new sf::RectangleShape(sf::Vector2f(size->X, size->Y)))
{
	shape->setFillColor(sf::Color(ObjectColor->R, ObjectColor->G, ObjectColor->B, ObjectColor->A));
	shape->setPosition(RenderLocation->X, RenderLocation->Y);
}

void SfmlRender::SpoonDraw(class Window* windowRef)
{
	((SfmlWindow*)windowRef)->Draw(*shape);
}