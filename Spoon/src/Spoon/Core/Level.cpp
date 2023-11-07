#include "snpch.h"
#include "Level.h"
#include "SObject.h"

Level::~Level()
{
	auto ListObject = EntityList;
	for (auto& object : ListObject)
	{
		delete object;
	}
}

void Level::UpdateEntity()
{
	for (auto entity : EntityList)
	{
		// TODO A changer pour avoir l'actuel tick X)
		entity->Tick(1/120);
	}
}
