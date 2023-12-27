#pragma once

#include "Core.h"
#include <snpch.h>

class SPOON_API InputHandler
{	
public:
	using Truc = std::pair<void*, std::function<void()>&>;

	void BindInput(void* objRef, std::function<void()>& func);

	void MassSuicide();

	std::vector<Truc> ListFollower;



};