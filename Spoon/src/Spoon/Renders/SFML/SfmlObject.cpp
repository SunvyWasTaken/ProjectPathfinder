#include "snpch.h"
#include "SfmlObject.h"
#include "TextureMgr.h"
#include "SfmlWindow.h"
#include "Spoon/Library/FMath.h"

ObjectRender* ObjectRender::Create(SObject* owner, const FColor& color)
{
	return new SfmlRender(owner, color);
}

void SfmlRender::OnUpdate()
{
	shape->setFillColor(sf::Color(ObjectColor.R, ObjectColor.G, ObjectColor.B, ObjectColor.A));
	shape->setPosition(ObjectTransform.Location.X, ObjectTransform.Location.Y);
}

SfmlRender::SfmlRender(SObject* owner, const FColor& color) : ObjectRender(owner, color), shape(new sf::RectangleShape(sf::Vector2f(ObjectTransform.Size.X, ObjectTransform.Size.Y)))
{
	OnUpdate();
}

void SfmlRender::SpoonDraw(class Window* windowRef)
{
	((SfmlWindow*)windowRef)->Draw(*shape);
}