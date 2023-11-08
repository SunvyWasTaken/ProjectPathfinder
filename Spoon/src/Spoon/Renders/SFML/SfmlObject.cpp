#include "snpch.h"
#include "SfmlObject.h"
#include "TextureMgr.h"
#include "SfmlWindow.h"
#include "Spoon/Library/FMath.h"

ObjectRender* ObjectRender::Create()
{
	return new SfmlRender();
}

SfmlRender::SfmlRender() : shape(new sf::RectangleShape(sf::Vector2f(10.f, 10.f)))
{
}

void SfmlRender::SpoonDraw(class Window* windowRef)
{
	shape->setFillColor(sf::Color(ObjectColor->R, ObjectColor->G, ObjectColor->B, ObjectColor->A));
	shape->setPosition(RenderLocation->X, RenderLocation->Y);
	((SfmlWindow*)windowRef)->Draw(*shape);
}