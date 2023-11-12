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

	void DestroyObject();

#pragma region Location

private:

	FVector2D ObjectLocation;

public:

	FVector2D GetLocation() const;

	void SetLocation(const FVector2D& loc);

#pragma endregion

#pragma region Render

private:

	ObjectRender* Render;

public:

	ObjectRender* GetRender() const { return Render; };

#pragma endregion

#pragma region Color

private:

	FColor ObjectColor;

public:

	FColor GetColor() const { return ObjectColor; };

	void SetColor(FColor color);

#pragma endregion

#pragma region World

private:

	class Level* WorldRef = nullptr;

public:

	inline class Level* GetWorld() const { return WorldRef; };

	void SetWorldRef(class Level* parentRef);

#pragma endregion

#pragma region Size

private:

	FVector2D ObjectSize;

public:

	void SetSize(const FVector2D& size);

	FVector2D GetSize() const;

#pragma endregion

};

