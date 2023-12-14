#pragma once
#include "Spoon/Core/SObject.h"
#include "vector"

class SNode : public SObject
{
public:
	SNode();
	virtual ~SNode();

	int GScore = 0;
	int HScore = 0;
	int FScore = GScore + HScore;

	void SetGScore(int newG);
	void SetHScore(int newH);
	int GetDistance(SNode* target);
	void SetConnection(SNode* connection);
	void AddNeighbour(std::vector<SNode*> Grid, int ID);
	void heuristic(SNode* neighbour, SNode* destination);

	bool bIsWalkable = true;
	std::vector<SNode*> Neighbours;
	SNode* Connection = nullptr;
};