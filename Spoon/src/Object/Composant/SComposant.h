#pragma once
#include "Spoon/Core/SObject.h"
#include "Spoon/Library/TColor.h"

class SComposant : public SObject
{

public:

	SComposant() = delete;

	SComposant(class SComposant* owner = nullptr);

	virtual ~SComposant();

	virtual void OnEvent(class SpoonEvent& event) = 0;

	virtual void OnUpdate() = 0;

	template <typename T = SComposant>
	T* GetOwner() const
	{
		return (T*)Owner;
	}

private:

	SComposant* Owner;

};
