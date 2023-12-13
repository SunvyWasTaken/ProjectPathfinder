#pragma once

#include "SComposant.h"

class SButton : public SComposant
{
public:
	virtual void OnEvent(class SpoonEvent& event) override;

private:

	bool OnMouseMoved(class MouseMovedEvent& event);

	bool OnMousePressed(class MouseButtonPressedEvent& event);
	
	bool OnMouseReleased(class MouseButtonReleasedEvent& event);

	bool bIsHover = false;

	bool bIsPressed = false;

protected:

	virtual void OnHovered() {};

	virtual void OnPressed() {};

	virtual void OnReleased() {};
};

