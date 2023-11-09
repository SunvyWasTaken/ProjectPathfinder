#pragma once

#include "Spoon/Core/SObject.h"

// Class widget qui va dériver en button ou text ect...
class SPOON_API SWidget : public SObject
{
protected:

	SWidget() = delete;

	SWidget(SWidget* parent) : ParentRef(parent) {};

	virtual ~SWidget() = default;

	SWidget* ParentRef;
};

template <typename T>
static T* CreateWidget(SWidget* parent)
{
	T* tmp = new T();
	static_cast<SWidget*>(tmp)->ParentRef = parent;
	return tmp;
}