#pragma 
#include "SObject.h"

class SPOON_API ObjectRender : public SObject
{
public:

	ObjectRender(SObject* owner, const FColor& color);

	virtual ~ObjectRender();

	virtual void SpoonDraw(class Window* windowRef) = 0;

	static ObjectRender* Create(SObject* owner, const FColor& color);

	template <typename T = SObject>
	T* GetOwner()
	{
		return (T*)Owner;
	}

private:

	SObject* Owner;

protected:

	FColor ObjectColor;

};