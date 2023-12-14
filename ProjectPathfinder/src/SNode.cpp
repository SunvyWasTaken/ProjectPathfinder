#include "SNode.h"
#include <random>

SNode::SNode()
{
}	  

SNode::~SNode()
{
}

void SNode::SetGScore(int newG)
{
	GScore = newG;
}

void SNode::SetHScore(int newH)
{
	HScore = newH;
}

int SNode::GetDistance(SNode* target)
{
	FVector2D Loc = GetLocation();
	FVector2D targetLoc = target->GetLocation();


	float distance = sqrt(pow(Loc.X - targetLoc.X, 2) + pow(Loc.Y - targetLoc.Y, 2));
		

	return distance * 10;
}

void SNode::SetConnection(SNode* connection)
{
	Connection = connection;
}

void SNode::AddNeighbour(std::vector<SNode*> Grid, int col, int row, int ID)
{
	// old neighbours systeme -> with magic number haha...
	/*if (GetLocation().X < col * 21 - 21)
		Neighbours.push_back(Grid[ID + 1]);

	if (GetLocation().X > 0)
		Neighbours.push_back(Grid[ID - 1]);

	if (GetLocation().Y < row * 21 - 21)
		Neighbours.push_back(Grid[ID + row]);

	if (GetLocation().Y > 0)
		Neighbours.push_back(Grid[ID - row]);*/


	if (x < col - 1)
		Neighbours.push_back(Grid[ID + 1]);

	if (x > 0)
		Neighbours.push_back(Grid[ID - 1]);

	if (y < row - 1)
		Neighbours.push_back(Grid[ID + row]);

	if (y > 0)
		Neighbours.push_back(Grid[ID - row]);

	if (bCanDiag)
	{
		if (x > 0 && y > 0)
			Neighbours.push_back(Grid[ID - 1 - row]);

		if (x < col - 1 && y > 0)
			Neighbours.push_back(Grid[ID + 1 - row]);

		if (x > 0 && y < row - 1)
			Neighbours.push_back(Grid[ID - 1 + row]);

		if (x < col - 1 && y < row - 1)
			Neighbours.push_back(Grid[ID + 1 + row]);
	}
	

}

void SNode::SetWalkable(bool isSpecialNode)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 100);


	if (dis(gen) >= 30 || isSpecialNode)
	{
		SetColor(FColor(0, 0, 255, 255));
		bIsWalkable = true;
	}
	else
	{
		bIsWalkable = false;
		SetColor(FColor(135, 135, 135, 255));
	}
}
