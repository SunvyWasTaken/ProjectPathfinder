#pragma once

#include "SNode.h"

class CustomButton;

class CustomNode : public SNode
{
public:
	CustomNode();

	void CycleState();

	void BeStart();
	void BeEnd();
	void BeEmpty();
	void BeObstacle();

	void SetLocation(const FVector2D& loc);

	void SetSquareSize(unsigned size);

	CustomButton* p_button;

	bool bIsStart;
	bool bIsEnd;

	bool bIsStartSet;
	bool bIsEndSet;

	char currentState;

private:
	FColor StartColor = FColor(93, 21, 209);
	FColor EndColor = FColor(237, 90, 90);
	FColor EmptyColor = FColor(183, 209, 21);
	FColor ObstacleColor = FColor(67, 75, 19);

	//todo use state machine (or template ?)
	char StartSate = 1;
	char EndState = 2;
	char EmptyState = 0;
	char ObstacleState = 3;
};