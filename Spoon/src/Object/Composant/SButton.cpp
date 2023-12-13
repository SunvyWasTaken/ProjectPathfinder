#include "SButton.h"
#include "Spoon/Events/MouseEvent.h"
#include "Spoon/Core/ObjectRender.h"
#include "Spoon/Core/Application.h"
#include "Object/SWidget.h"
#include <snpch.h>

SButton::SButton(SComposant* owner) : SComposant(owner)
{
	SetSize(FVector2D(30, 60));
}

SButton::~SButton()
{
	delete Child;
}

void SButton::OnEvent(SpoonEvent& event)
{
	EventDispatcher dispatcher(event);
	dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(SButton::OnMouseMoved));
	dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(SButton::OnMousePressed));
	dispatcher.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(SButton::OnMouseReleased));
}

void SButton::OnUpdate()
{
	Render->OnUpdate();
	if (Child)
	{
		Child->GetRender()->OnUpdate();
	}
}

void SButton::AddChild(SComposant* _child)
{
	Child = _child;
	Application::Get().GetLayerOverlay()->AddComposant(Child);
}

bool SButton::OnMouseMoved(MouseMovedEvent& event)
{
	const FVector2D mousePosition(event.GetX(), event.GetY());
	if (!bIsHover && IsInBound(mousePosition))
	{
		bIsHover = true;
		OnHovered();
		return true;
	}
	else if (bIsHover && !IsInBound(mousePosition))
	{
		bIsHover = false;
	}
	return false;
}

bool SButton::OnMousePressed(MouseButtonPressedEvent& event)
{
	if(event.GetMouseButton() != 0)
		return false;

	if (bIsHover && !bIsPressed)
	{
		bIsPressed = true;
		OnPressed();
		return true;
	}
	return false;
}

bool SButton::OnMouseReleased(MouseButtonReleasedEvent& event)
{
	if (event.GetMouseButton() != 0)
		return false;

	if (bIsPressed)
	{
		bIsPressed = false;
		OnReleased();
		return true;
	}
	return false;
}