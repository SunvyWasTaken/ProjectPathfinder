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
	for (unsigned i = 0; i < EntityList.size(); ++i)
	{
		
	}
}
