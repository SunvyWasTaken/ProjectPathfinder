#pragma once

#include "Core.h"
#include "Spoon/Events/SpoonEvent.h"

class SPOON_API Layer
{
public:
	explicit Layer(const std::string& name = "Layer");
	virtual ~Layer();

	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void OnUpdate() {}
	virtual void OnEvent(SpoonEvent& event) {}


	// Partie pour pouvoir print dans le Debug.
	inline const std::string& GetName() const { return m_DebugName; };
protected:
	std::string m_DebugName;

};
