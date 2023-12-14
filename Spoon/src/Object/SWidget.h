#pragma once

#include "Spoon/Core/Layer.h"
#include "Spoon/Core/SObject.h"
#include <snpch.h>

// Class widget qui va d�river en button ou text ect...
class SPOON_API SWidget : public Layer
{
public:

	virtual void OnEvent(SpoonEvent& event) override;

	virtual void OnUpdate() override;

	virtual void Render(class Window* window);

	void AddComposant(class SComposant* compo);

private:
	
	std::vector<class SComposant*> ComposantList;

};