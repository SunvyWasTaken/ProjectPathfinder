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

	void AddActorLocation(FVector2D& _val);

	ObjectRender* GetRender() const { return Render; };

protected:

	FVector2D ObjectLocation;

	ObjectRender* Render;

};

