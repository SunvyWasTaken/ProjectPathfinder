#include "CustomNode.h"

#include "CustomButton.h"

CustomNode::CustomNode() : p_button(nullptr), SNode()
{
	p_button = CreateWidget<CustomButton>();
	p_button->p_node = this;
	BeEmpty();
}

void CustomNode::CycleState()
{
	if (currentState == EmptyState)
	{
		if (!bIsStartSet)
			BeStart();
		else if (!bIsEndSet)
			BeEnd();
		else
			BeObstacle();
	}

	else if (currentState == StartSate)
	{
		if (!bIsEndSet)
			BeEnd();
		else
			BeObstacle();
	}

	else if (currentState == EndState)
		BeObstacle();
	
	else
		BeEmpty();
}

void CustomNode::BeStart()
{
	bIsWalkable = true;
	bIsEnd = false;
	bIsStart = true;

	currentState = StartSate;

	p_button->SetColor(StartColor);
}

void CustomNode::BeEnd()
{
	bIsWalkable = true;
	bIsEnd = true;
	bIsStart = false;

	currentState = EndState;

	p_button->SetColor(EndColor);
}

void CustomNode::BeEmpty()
{
	bIsWalkable = true;
	bIsEnd = false;
	bIsStart = false;

	currentState = EmptyState;

	p_button->SetColor(EmptyColor);
}

void CustomNode::BeObstacle()
{
	bIsWalkable = false;
	bIsEnd = false;
	bIsStart = false;

	currentState = ObstacleState;

	p_button->SetColor(EmptyColor);
}

void CustomNode::SetLocation(const FVector2D& loc)
{
	SNode::SetLocation(loc);
	p_button->SetLocation(loc);
}

void CustomNode::SetSquareSize(unsigned size)
{
	p_button->SetSize(FVector2D(size, size));
}
