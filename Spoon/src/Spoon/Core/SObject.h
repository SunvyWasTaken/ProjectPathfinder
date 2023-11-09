#pragma once
#include "Core.h"
#include <snpch.h>

class ObjectRender;

// Object base. 
class SPOON_API SObject
{
public:
	
	SObject();

	virtual ~SObject();

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

	inline class Level* GetWorld() const { return WorldRef; };

	FVector2D GetLocation() const;

	void SetLocation(const FVector2D& loc);

	void DestroyObject();

	ObjectRender* GetRender() const { return Render; };

	void SetColor(FColor color);

	FColor GetColor() const { return ObjectColor; };

	void SetParent(class Level* parentRef);

private:

	FVector2D ObjectLocation;

	FColor ObjectColor;

	ObjectRender* Render;

	class Level* WorldRef = nullptr;

	float TimerDestroy = 5.f;

	float CurrentTimeAlive = 0;

};

