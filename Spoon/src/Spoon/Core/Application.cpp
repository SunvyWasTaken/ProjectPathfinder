#include "Application.h"
#include "Level.h"
#include "Window.h"
#include "Spoon/Events/Event.h"
#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application::Application()
{
	WindowRef = std::unique_ptr<Window>(Window::Create());
	WindowRef->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	CurrentLevel = std::unique_ptr<Level>(new Level());
}

Application::~Application()
{
}

void Application::Run()
{
	while (bIsRunning)
	{
		WindowRef->OnUpdate();
	}
}

void Application::OnEvent(Event& e)
{
	// Ici dfaire un event type pour les trier.
		// call si l'event est window close.
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	bIsRunning = false;
	return true;
}

bool Application::OnKeyPressed(KeyPressedEvent& e)
{
	std::cout << e.ToString() << std::endl;
	return true;
}

Level* Application::GetWorld() const
{
	return nullptr;
}
