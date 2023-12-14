#pragma once

#include "SComposant.h"

class SPOON_API SButton : public SComposant
{
public:

	SButton(class SComposant* owner = nullptr);

	virtual ~SButton();

	virtual void OnEvent(class SpoonEvent& event) override;

	virtual void OnUpdate() override;

	void AddChild(SComposant* _child);

private:

	bool OnMouseMoved(class MouseMovedEvent& event);

	bool OnMousePressed(class MouseButtonPressedEvent& event);
	
	bool OnMouseReleased(class MouseButtonReleasedEvent& event);

	bool bIsHover = false;

	bool bIsPressed = false;

	SComposant* Child = nullptr;

protected:

	virtual void OnHovered() {};

	virtual void OnPressed() {};

	virtual void OnReleased() {};
};

