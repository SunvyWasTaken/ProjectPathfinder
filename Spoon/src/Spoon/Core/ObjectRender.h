#pragma 
#include "Core.h"

class SPOON_API ObjectRender
{
public:

	ObjectRender();

	virtual ~ObjectRender();

	virtual void SpoonDraw(class Window* windowRef) = 0;

	static ObjectRender* Create();

	FVector2D* RenderLocation;

	FColor* ObjectColor;

};