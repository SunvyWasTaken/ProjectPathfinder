#include "Spoon.h"
#include "CustomNode.h"
#include "AStar.h"

class PathApp : public Application
{
public:
	PathApp() : Application("Pathfinder", FVector2D(1280, 720))
	{}
};

Application* CreateApplication()
{
	return new PathApp();
}

void StartAStar(Application* app, unsigned GridPosition, const std::vector<SNode*>& Grid)
{
	AStar* algo = app->GetWorld()->SpawnActor<AStar>(FTransform());
	algo->SetLocation(FVector2D(GridPosition, GridPosition));

	for(auto &it : Grid)
	{
		CustomNode* tempNode = static_cast<CustomNode*>(it);
		if (tempNode->currentState == CustomNode::StartSate)
			algo->StartNode = it;
		else if (tempNode->currentState == CustomNode::EndState)
			algo->DestinationNode = it;
	}

	if (algo->StartNode == nullptr) {
		// define the start node and the destination node
		CustomNode* Start = static_cast<CustomNode*>(Grid[0]);
		Start->BeStart();
		algo->StartNode = Start;
	}
	if (algo->DestinationNode == nullptr) {
		CustomNode* Destination = static_cast<CustomNode*>(Grid[Grid.size() - 1]);
		Destination->BeEnd();
		algo->DestinationNode = Destination;
	}

	// Put the start and destination node into the algo
	algo->OpenList.push_back(algo->StartNode);
}

struct StartButton : SButton
{
	StartButton(SComposant* owner) : SButton(owner) {};
	void OnPressed() override { StartAStar(app, pos, *grid); };
	Application* app;
	unsigned pos;
	std::vector<SNode*>* grid;
};

int main()
{
	auto* app = CreateApplication();

#pragma region Squares

	// Make a Grid of Square
	//todo: create grid class to be able to deal with inter-square operation (setting isEndSet/isStartSet)
	std::vector<SNode*> Grid;
	unsigned GridPosition = 125;
	unsigned GridSize = 10;
	unsigned SquareSize = 10;
	unsigned Padding = 40;

	for (unsigned i = 0; i < GridSize; i++)
	{	
		for (unsigned j = 0; j < GridSize; j++)
		{
			CustomNode* Node = app->GetWorld()->SpawnActor<CustomNode>(FTransform(FVector2D(SquareSize * j, SquareSize * i), FVector2D(SquareSize)));

			Node->SetLocation(FVector2D(j * (SquareSize + Padding) + GridPosition, i * (SquareSize + Padding) + GridPosition));
			Node->SetColor(FColor::White());
			Node->SetSquareSize(SquareSize + Padding);

			Node->x = j;
			Node->y = i;

			Grid.push_back(static_cast<SNode*>(Node));
		}
	}

	int ID = 0;
	for (unsigned i = 0; i < Grid.size() - 1; i++)
	{
		Grid[ID]->AddNeighbour(Grid, GridSize, GridSize, ID);
		ID++;
	}
#pragma endregion

#pragma region StartButton
	StartButton* startButton = CreateWidget<StartButton>();
	startButton->app = app;
	startButton->pos = GridPosition;
	startButton->grid = &Grid;
	startButton->SetLocation(FVector2D(950, 372));
	startButton->SetSize(FVector2D(460, 100));
	startButton->SetColor(FColor(217));
#pragma endregion

	app->Run();
	delete app;

	return 0;
}

