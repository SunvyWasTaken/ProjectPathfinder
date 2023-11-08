#include "snpch.h"
#include "Level.h"
#include "SObject.h"

Level::~Level()
{
	auto ListObj = AddEntityList;
	for (auto& obj : ListObj)
	{
		delete obj;
	}
	auto ListObject = EntityList;
	for (auto& object : ListObject)
	{
		delete object;
	}
}

void Level::UpdateEntity()
{
	for (auto& addEntity : AddEntityList)
	{
		EntityList.push_back(addEntity);
		addEntity->BeginPlay();
	}
	AddEntityList.clear();
	for (auto& entity : EntityList)
	{
		// TODO A changer pour avoir l'actuel tick X)
		entity->Tick(1/120);
	}
}