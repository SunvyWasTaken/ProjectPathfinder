#pragma once
#include "Spoon/Core/SObject.h"
#include "vector"
#include "Spoon/Library/FMath.h"

class SNode;

class AStar : public SObject
{
public:
	AStar();
	virtual ~AStar();

	/*void SetStartNode(const FVector2D& loc);
	void SetDestinationNode(const FVector2D& loc);*/

	virtual void Tick(float Deltatime) override;

	std::vector<SNode*> Search();

	std::vector<SNode*> OpenList;
	std::vector<SNode*> CloseList;
	std::vector<SNode*> Path;
	SNode* StartNode;
	SNode* DestinationNode;
	bool bCanDiag = false;

	FColor OpenColor;
	FColor CloseColor;
	FColor PathColor;
};

