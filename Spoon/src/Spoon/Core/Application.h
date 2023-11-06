#pragma once
#include "snpch.h"
#include "Core.h"

class Level;
class Window;

class SPOON_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

	void OnEvent();

	void OnWindowClose();

	Level* GetWorld() const;

private:

	std::unique_ptr<Window> WindowRef;

	bool bIsRunning = true;

	std::unique_ptr<Level> CurrentLevel;

};
