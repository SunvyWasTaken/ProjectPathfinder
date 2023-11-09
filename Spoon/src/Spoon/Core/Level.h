#pragma once
#include "Core.h"
#include "Spoon/Library/FMath.h"
#include "Window.h"
#include "SObject.h"

#include <vector>

// TODO Levels
// je dois déplacer pour faire en sorte que ce soit pas à moi de faire ça.
// Faire en sorte d'avoir un objet levels qui gere tous seul les entités qui seront crée.
class SPOON_API Level
{
public:

	virtual ~Level();

	void UpdateEntity(double deltatime);

	template<typename T>
	__forceinline T* SpawnActor(FVector2D _location)
	{
		T* tmp = new T();
		if (tmp)
		{
			tmp->SetLocation(_location);
			tmp->SetParent(this);
		}
		// Cast vide du coup c mort.
		return tmp;
	}

	std::vector<SObject*> GetEntityList() const { return EntityList; }

	void RemoveObject(class SObject* obj);

	void AddObject(class SObject* obj);

	void DestroyEntity(class SObject* obj);
	
protected:

	// Entity actuellement dans le world.
	std::vector<SObject*> EntityList;

	std::vector<SObject*> AddEntityList;
};

