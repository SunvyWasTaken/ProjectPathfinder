#pragma once
#include "Object/SActor.h"
#include "vector"

class SNode;

class AStar : public SActor
{
public:
	AStar();
	virtual ~AStar();

	/*void SetStartNode(const FVector2D& loc);
	void SetDestinationNode(const FVector2D& loc);*/

	virtual void Tick(float Deltatime) override;

	void Search();

	std::vector<SNode*> OpenList;
	std::vector<SNode*> CloseList;
	std::vector<SNode*> Path;
	std::vector<SNode*> Obstacles;
	SNode* StartNode = nullptr;
	SNode* DestinationNode = nullptr;
	bool bIsPathFound = false;
#if DEBUG
	int Iterator = 0;
#endif
	

	FColor OpenColor;
	FColor CloseColor;
	FColor PathColor;
};

