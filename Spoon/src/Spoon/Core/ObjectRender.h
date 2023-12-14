#pragma 
#include "SObject.h"

class SPOON_API ObjectRender : public SObject
{
public:

	ObjectRender(SObject* owner, FColor* color);

	virtual ~ObjectRender();

	virtual void SpoonDraw(class Window* windowRef) = 0;

	static ObjectRender* Create(SObject* owner, FColor* color);

	template <typename T = SObject>
	T* GetOwner()
	{
		return (T*)Owner;
	}

	virtual void OnUpdate() = 0;

private:

	SObject* Owner;

protected:

	FColor* ObjectColor;

};