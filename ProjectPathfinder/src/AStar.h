#pragma once
#include "Object/SActor.h"
#include "vector"
#include "Spoon/Library/FMath.h"

class SNode;

class AStar : public SActor
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
	std::vector<SNode*> Obstacles;
	SNode* StartNode;
	SNode* DestinationNode;
	bool bIsPathFound = false;
	int Iterator = 0;

	FColor OpenColor;
	FColor CloseColor;
	FColor PathColor;
};

