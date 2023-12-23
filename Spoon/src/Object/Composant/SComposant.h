#pragma once
#include "Spoon/Core/SObject.h"
#include "Spoon/Library/TColor.h"

class SComposant : public SObject
{

friend class SWidget;

public:

	SComposant(class SComposant* owner = nullptr);

	virtual ~SComposant();

	virtual void OnEvent(class SpoonEvent& event) = 0;

	virtual void OnUpdate() = 0;

	class ObjectRender* GetRender() const { return Render; }

	template <typename T = SComposant>
	T* GetOwner() const
	{
		return (T*)Owner;
	}

	FColor& const GetColor() { return ObjectColor; }

	void SetColor(const FColor& _color) { ObjectColor = _color; }

private:

	bool RenderComposant(class Window* window);

	SComposant* Owner;

protected:

	bool const IsInBound(const FVector2D& loc) const;

	class ObjectRender* Render;

	FColor ObjectColor;

};
