#pragma once
#include "Core.h"
#include "Spoon/Library/FMath.h"
#include "Window.h"
#include "Object/SActor.h"

#include <vector>

// TODO Levels
// je dois d�placer pour faire en sorte que ce soit pas � moi de faire �a.
// Faire en sorte d'avoir un objet levels qui gere tous seul les entit�s qui seront cr�e.
class SPOON_API Level
{
public:

	virtual ~Level();

	void UpdateEntity(double deltatime);

	template<typename T = SActor>
	__forceinline T* SpawnActor(FTransform transform)
	{
		T* tmp = new T();
		if (tmp)
		{
			tmp->SetTransform(transform);
			tmp->SetWorldRef(this);
		}
		// Cast vide du coup c mort.
		return tmp;
	}

	std::vector<SActor*> GetEntityList() const { return EntityList; }

	void RemoveObject(class SActor* obj);

	void AddObject(class SActor* obj);
	
protected:

	// Entity actuellement dans le world.
	std::vector<SActor*> EntityList;

	std::vector<SActor*> AddEntityList;
};

