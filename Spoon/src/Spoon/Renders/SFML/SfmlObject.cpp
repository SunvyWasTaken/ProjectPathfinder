#include "snpch.h"
#include "SfmlObject.h"
#include "TextureMgr.h"
#include "SfmlWindow.h"
#include "Spoon/Library/FMath.h"

ObjectRender* ObjectRender::Create(SObject* owner, FColor* color)
{
	return new SfmlRender(owner, color);
}

void SfmlRender::OnUpdate()
{
	shape->setFillColor(sf::Color(ObjectColor->R, ObjectColor->G, ObjectColor->B, ObjectColor->A));
	shape->setPosition(GetOwner()->GetLocation().X, GetOwner()->GetLocation().Y);
	shape->setSize(sf::Vector2f(GetOwner()->GetSize().X, GetOwner()->GetSize().Y));
}

SfmlRender::SfmlRender(SObject* owner, FColor* color) : ObjectRender(owner, color), shape(new sf::RectangleShape())
{
	OnUpdate();
}

void SfmlRender::SpoonDraw(class Window* windowRef)
{
	((SfmlWindow*)windowRef)->Draw(*shape);
}