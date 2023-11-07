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

	void UpdateEntity();

	template<typename T>
	__forceinline SObject* SpawnActor(FVector2D _location)
	{
		SObject* tmp = new T();
		if (tmp)
		{
			tmp->AddActorLocation(_location);
			EntityList.push_back(tmp);
		}
		// Cast vide du coup c mort.
		return tmp;
	}

	std::vector<SObject*> GetEntityList() const { return EntityList; }
	
protected:

	// Entity actuellement dans le world.
	std::vector<SObject*> EntityList;
};

