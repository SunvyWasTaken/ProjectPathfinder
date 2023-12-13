#pragma once
#include "Core.h"
#include "LayerStack.h"
#include <snpch.h>

class Level;
class Window;


class SPOON_API Application
{
public:
	Application();

	Application(std::string windowName, FVector2D screensize);

	virtual ~Application();

	void Init();

	void Run();

	// Dispatch Event
	void OnEvent(class SpoonEvent& e);

	void PushOverlay(Layer* layer);
	void PushLayer(Layer* layer);

	Level* GetWorld() const;

private:

	// Event
	bool OnWindowClose(class WindowCloseEvent& e);
	bool OnKeyPressed(class KeyPressedEvent& e);
	bool OnAppTick(class AppTickEvent& e);
	bool OnRender(class AppRenderEvent& e);
	bool OnWindowResize(class WindowResizeEvent& e);

	#pragma region WindowProperty

	FVector2D ScreenSize;

	std::string WindowName;

	#pragma endregion

private:

	Window* WindowRef;

	bool bIsRunning = true;

	Level* CurrentLevel;

	LayerStack m_LayerStack;

};
