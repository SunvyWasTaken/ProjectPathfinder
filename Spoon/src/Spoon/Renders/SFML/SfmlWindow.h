#pragma once
#include "snpch.h"
#include "Spoon/Core/Window.h"

#include <SFML/Graphics.hpp>

class SPOON_API SfmlWindow : public Window
{
public:
	SfmlWindow(const WindowsProps& props);
	virtual ~SfmlWindow() override;

	void OnUpdate() override;

	inline void SetEventCallback(const std::function<void()>& callback) override { EventCallBack = callback;};
	
	unsigned int GetWidth() const override;
	unsigned int GetHeight() const override;

private:
	
	std::unique_ptr<sf::RenderWindow> WindowRef;
	
	virtual void Init(const WindowsProps& props);

	virtual void Shutdown();
	struct Data
	{
		std::string Title;
		unsigned int Width, Height;
	};

	Data m_Data;

	// Function to callback
	std::function<void()> EventCallBack;
};
