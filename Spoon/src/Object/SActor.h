#pragma once

#include "Spoon/Core/SObject.h"
#include "Spoon/Library/TColor.h"

class SPOON_API SActor : public SObject
{

friend class Level;

public:

	SActor();

	virtual ~SActor();

	void DestroyActor();

	class Level* GetWorld() const;

	FColor GetColor() const { return ObjectColor; };

	void SetColor(const FColor& color);

protected:

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

private:

	void SetWorldRef(class Level* parentRef);

private:

	FColor ObjectColor;

	class Level* WorldRef;

};

