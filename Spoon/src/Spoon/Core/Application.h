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

	void OnEvent(class Event& e);

	bool OnWindowClose(class WindowCloseEvent& e);

	bool OnKeyPressed(class KeyPressedEvent& e);

	Level* GetWorld() const;

private:

	std::unique_ptr<Window> WindowRef;

	bool bIsRunning = true;

	std::unique_ptr<Level> CurrentLevel;

};
