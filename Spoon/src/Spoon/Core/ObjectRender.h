#pragma 
#include "Core.h"

class SPOON_API ObjectRender
{
public:

	ObjectRender(FVector2D* loc = nullptr, FVector2D* size = nullptr, FColor* color = nullptr);

	virtual ~ObjectRender();

	virtual void SpoonDraw(class Window* windowRef) = 0;

	static ObjectRender* Create(FVector2D* loc = nullptr, FVector2D* size = nullptr, FColor* color = nullptr);

protected:

	FVector2D* RenderLocation;

	FVector2D* ObjectSize;

	FColor* ObjectColor;

};