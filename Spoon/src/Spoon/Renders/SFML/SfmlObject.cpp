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

void SfmlRender::Init()
{
	shape->setFillColor(sf::Color(125.f, 125.f, 0.f, 255.f));
}

void SfmlRender::SpoonDraw(class Window* windowRef)
{
	shape->setPosition(sf::Vector2f(RenderLocation->X, RenderLocation->Y));
	((SfmlWindow*)windowRef)->Draw(*shape);
}