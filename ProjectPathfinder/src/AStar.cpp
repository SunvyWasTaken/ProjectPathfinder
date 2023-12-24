#include "AStar.h"
#include "SNode.h"


AStar::AStar()
{
	//Open Is green, close is red, path is White and obstacle is Grey
	OpenColor = FColor::Green();
	CloseColor = FColor::Red();
	PathColor = FColor::White();
}

AStar::~AStar()
{
}

//void AStar::SetStartNode(const FVector2D& loc)
//{
//	StartNode = new SNode;
//	StartNode->SetLocation(loc);
//}
//
//void AStar::SetDestinationNode(const FVector2D& loc)
//{
//	DestinationtNode = new SNode;
//	DestinationNode->SetLocation(loc);
//}

void AStar::Tick(float Deltatime)
{
	if (!bIsPathFound && StartNode && DestinationNode)
	{
		Search();
	}
}

void AStar::Search()
{
	//OpenList.push_back(StartNode);
	if (!OpenList.empty())
	{
#if DEBUG
		Iterator++;
#endif // DEBUG
		// current has to be the node with the lowest f
		SNode* Current;
		Current = OpenList[0];
		bool InSearch;
		int CostToNeighbour;

		for (auto node : OpenList)
			if (node->FScore < Current->FScore || node->FScore == Current->FScore && node->HScore  < Current->HScore)
				Current = node;

		// add to the CloseList and remove from the OpenList as it is now process
		CloseList.push_back(Current);
		auto tmp = std::find(OpenList.begin(), OpenList.end(), Current);
		if (tmp != OpenList.end())
		{
			OpenList.erase(tmp);
		}

		Current->SetColor(CloseColor);

		// When Current Is Destination Add all node in the Path Vector and change its color to display it
		FVector2D CurrentLoc = Current->GetLocation();
		FVector2D DestinationLoc = DestinationNode->GetLocation();
		if (CurrentLoc == DestinationLoc)
		{
			SNode* CurrentPathTile = DestinationNode;
			while(CurrentPathTile->Connection)
			{
				Path.push_back(CurrentPathTile);
				CurrentPathTile = CurrentPathTile->Connection;
			}

			for (auto tile : Path)
				tile->SetColor(PathColor);
			StartNode->SetColor(PathColor);
			bIsPathFound = true;
#if DEBUG
			std::cout << "nombre d'iteration " << Iterator << std::endl;
#endif // DEBUG

			return;
		}

		// Calcul H and G Score of all Neighbours of Current to deteremine F Score (Closest node to Destination)
		for (auto neighbour : Current->Neighbours)
		{
			if (neighbour->bIsWalkable && !(std::find(CloseList.begin(), CloseList.end(),neighbour) != CloseList.end()))
			{
				InSearch = std::find(OpenList.begin(), OpenList.end(), neighbour) != OpenList.end();
				
				// TO DO
				// add getdistance into node that calcul the distance between a node and another one	-> Done
				CostToNeighbour = Current->GScore + Current->GetDistance(neighbour);

				if (!InSearch || CostToNeighbour < neighbour->GScore)
				{
					neighbour->SetGScore(CostToNeighbour);
					neighbour->SetConnection(Current);

					if (!InSearch)
					{
						neighbour->SetHScore(neighbour->GetDistance(DestinationNode));
						neighbour->FScore = neighbour->GScore + neighbour->HScore;
						
						OpenList.push_back(neighbour);
						neighbour->SetColor(OpenColor);
					}
				}
			}
		}

	}
	else
	{
		// no solution
		//std::cout << "Finish";
		return;
	}
	return;
}
