#pragma once
#include "Core.h"

class Level;
class Window;

class SPOON_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

	void OnEvent(class SpoonEvent& e);

	bool OnWindowClose(class WindowCloseEvent& e);

	bool OnKeyPressed(class KeyPressedEvent& e);

	bool OnAppTick(class AppTickEvent& e);

	bool OnRender(class AppRenderEvent& e);

	bool OnWindowResize(class WindowResizeEvent& e);

	Level* GetWorld() const;

private:

	Window* WindowRef;

	bool bIsRunning = true;

	Level* CurrentLevel;

};
