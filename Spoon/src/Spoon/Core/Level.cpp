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

void Level::UpdateEntity(double deltatime)
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
		entity->Tick(deltatime);
	}
}

void Level::RemoveObject(SObject* obj)
{
	auto tmp = std::find(EntityList.begin(), EntityList.end(), obj);
	if (tmp == EntityList.end())
	{
		std::cout << "Objet non trouver dans la list objets" << std::endl;
		return;
	}
	EntityList.erase(tmp);
}

void Level::AddObject(SObject* obj)
{
	if (!obj)
	{
		std::cout << "Add objet null" <<  std::endl;
		return;
	}
	auto tmp = std::find(EntityList.begin(), EntityList.end(), obj);
	if (tmp != EntityList.end())
	{
		std::cout << "Objet already in the list" << std::endl;
		return;
	}
	AddEntityList.push_back(obj);
}

