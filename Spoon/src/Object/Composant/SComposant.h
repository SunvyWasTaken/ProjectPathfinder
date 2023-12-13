#pragma once
#include "Spoon/Core/SObject.h"

class SComposant : public SObject
{

friend class SWidget;

public:
	SComposant();
	virtual ~SComposant();

	virtual void OnEvent(class SpoonEvent& event) {};

	void OnUpdate();

private:

	class ObjectRender* Render;

protected:

	bool const IsInBound(const FVector2D& loc) const;

	FColor ObjectColor;

};
