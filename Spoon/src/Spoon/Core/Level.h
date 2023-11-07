#pragma once
#include "Core.h"
#include "Spoon/Library/FMath.h"
#include "Window.h"
#include "SObject.h"

#include <vector>

// TODO Levels
// je dois d�placer pour faire en sorte que ce soit pas � moi de faire �a.
// Faire en sorte d'avoir un objet levels qui gere tous seul les entit�s qui seront cr�e.
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
			tmp->SetLocation(_location);
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

