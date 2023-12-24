#pragma once
#include "Object/SActor.h"
#include "vector"

class SNode : public SActor
{
public:
	SNode();
	virtual ~SNode();

	int x;
	int y;

	int GScore = 0;
	int HScore = 0;
	int FScore = GScore + HScore;

	void SetGScore(int newG);
	void SetHScore(int newH);
	int GetDistance(SNode* target);
	void SetConnection(SNode* connection);
	void AddNeighbour(std::vector<SNode*> Grid, int col, int row, int ID);
	void SetWalkable(bool isSpecialNode);

	bool bCanDiag = false;
	bool bIsWalkable = true;
	std::vector<SNode*> Neighbours;
	SNode* Connection = nullptr;
};

