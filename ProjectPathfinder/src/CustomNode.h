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

	//todo: set when start and end are assigned
	bool bIsStartSet = false;
	bool bIsEndSet = false;

	char currentState;

	//todo use state machine (or template ?)
	static const char StartSate = 1;
	static const char EndState = 2;
	static const char EmptyState = 0;
	static const char ObstacleState = 3;

private:
	FColor StartColor = FColor(93, 21, 209);
	FColor EndColor = FColor(237, 90, 90);
	FColor EmptyColor = FColor(183, 209, 21);
	FColor ObstacleColor = FColor(67, 75, 19);
};