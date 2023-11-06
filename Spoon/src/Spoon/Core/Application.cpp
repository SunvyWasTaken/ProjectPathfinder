#include "Application.h"
#include "Level.h"

Application::Application()
{
	WindowRef = std::unique_ptr<Window>(Window::Create());
	WindowRef->SetEventCallback(std::bind(&Application::OnEvent, this));

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

void Application::OnEvent()
{
	// Ici dfaire un event type pour les trier.
		// call si l'event est window close.
		OnWindowClose();
}

void Application::OnWindowClose()
{
	bIsRunning = false;
}

Level* Application::GetWorld() const
{
	return nullptr;
}
