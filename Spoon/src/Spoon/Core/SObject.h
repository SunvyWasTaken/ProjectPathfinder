#pragma once
#include "Core.h"
#include "Spoon/Library/FMath.h"

class ObjectRender;

// Object base. 
class SPOON_API SObject
{
public:
	
	SObject();

	virtual ~SObject();

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

	FVector2D GetLocation() const;

	void SetLocation(const FVector2D& loc);

	ObjectRender* GetRender() const { return Render; };

protected:

	FVector2D ObjectLocation;

	ObjectRender* Render;

};

