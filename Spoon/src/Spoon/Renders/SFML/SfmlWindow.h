#pragma once
#include "snpch.h"
#include "Spoon/Core/Window.h"

#include <SFML/Graphics.hpp>

namespace sf { class Shape; };

class SPOON_API SfmlWindow : public Window
{
public:
	SfmlWindow(const WindowsProps& props);
	virtual ~SfmlWindow() override;

	void OnUpdate() override;

	inline void SetEventCallback(const EventCallBackFn& callback) override { EventCallBack = callback;};
	
	unsigned int GetWidth() const override;
	unsigned int GetHeight() const override;

	void Draw(sf::Shape& currentShape);

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

	void HandleEvent(sf::Event& event);

	// Function to callback
	EventCallBackFn EventCallBack;
};

