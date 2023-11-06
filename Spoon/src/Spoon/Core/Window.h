#pragma once
#include "Spoon/Core/Core.h"

struct WindowsProps
{
	std::string Title;

	unsigned int Width;
	unsigned int Height;

	WindowsProps(const std::string& title = "SpoonEngine",
				unsigned int width = 1280,
				unsigned int height = 720)
			: Title(title), Width(width), Height(height)
	{}
};

class SPOON_API Window
{
public:

	virtual ~Window() {};

	virtual void OnUpdate() = 0;
	virtual void SetEventCallback(const std::function<void()>& callback) = 0;
	virtual unsigned int GetWidth() const = 0;
	virtual unsigned int GetHeight() const = 0;

	static Window* Create(const WindowsProps& props = WindowsProps());
};
