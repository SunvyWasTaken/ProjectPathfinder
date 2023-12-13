#pragma once

#include "Spoon/Core/Layer.h"
#include "Spoon/Core/SObject.h"

// Class widget qui va dériver en button ou text ect...
class SPOON_API SWidget : public Layer
{
public:

	virtual void OnEvent(SpoonEvent& event) override;

protected:

	bool OnMouseEvent(class MouseMovedEvent& mouseMoved);

};