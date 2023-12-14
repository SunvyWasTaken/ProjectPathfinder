#include "SNode.h"

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
	Connection = new SNode;
	Connection = connection;
}

void SNode::AddNeighbour(std::vector<SNode*> Grid, int ID)
{
	if (GetLocation().X < 10 * 50 - 50)
		Neighbours.push_back(Grid[ID + 1]);

	if (GetLocation().X > 0)
		Neighbours.push_back(Grid[ID - 1]);

	if (GetLocation().Y < 10 * 50 - 50)
		Neighbours.push_back(Grid[ID + 10]);

	if (GetLocation().Y > 0)
		Neighbours.push_back(Grid[ID - 10]);
}

void SNode::heuristic(SNode* neighbour, SNode* destination)
{
}
