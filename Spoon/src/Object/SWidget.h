#pragma once

#include "Spoon/Core/Layer.h"
#include "Spoon/Core/SObject.h"
#include <snpch.h>

// Class widget qui va dériver en button ou text ect...
class SPOON_API SWidget : public Layer
{
public:

	virtual void OnEvent(SpoonEvent& event) override;

	virtual void OnUpdate() override;

private:
	
	std::vector<class SComposant*> ComposantList;

};