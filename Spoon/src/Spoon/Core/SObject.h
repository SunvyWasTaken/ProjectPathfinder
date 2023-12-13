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

	virtual void BeginPlay() = 0;

	virtual void Tick(float DeltaTime) = 0;

protected:

	FTransform ObjectTransform;

public:

	FVector2D GetLocation() const;

	void SetLocation(const FVector2D& loc);

	FVector2D GetSize() const;

	void SetSize(const FVector2D& size);

	FTransform GetTransform() const;

	void SetTransform(const FTransform& transform);

};

