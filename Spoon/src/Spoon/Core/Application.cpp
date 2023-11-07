#include "snpch.h"
#include "Application.h"
#include "Level.h"

#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"
#include "Spoon/Renders/SFML/SfmlObject.h"

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application::Application()
{
	WindowRef = Window::Create();
	WindowRef->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

	CurrentLevel = new Level();
}

Application::~Application()
{
	delete CurrentLevel;
}

void Application::Run()
{
	while (bIsRunning)
	{
		WindowRef->OnUpdate();
	}
}

void Application::OnEvent(SpoonEvent& e)
{
	// Ici dfaire un event type pour les trier.
		// call si l'event est window close.
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
	dispatcher.Dispatch<AppTickEvent>(BIND_EVENT_FN(Application::OnAppTick));
	dispatcher.Dispatch<AppRenderEvent>(BIND_EVENT_FN(Application::OnRender));
}

bool Application::OnWindowClose(WindowCloseEvent& e)
{
	bIsRunning = false;
	return true;
}

bool Application::OnKeyPressed(KeyPressedEvent& e)
{
	std::cout << e.ToString() << std::endl;
	// Resend les event à tous les objets qui possède un bind
	// je sais pas encore vraiment faudrait que je fasse un system de listerner
	// comme ça des que la fonction et call pouf je call tous les autres.
	return true;
}

bool Application::OnAppTick(AppTickEvent& e)
{
	CurrentLevel->UpdateEntity();
	return true;
}

bool Application::OnRender(AppRenderEvent& e)
{
	for (auto entity : CurrentLevel->GetEntityList())
	{
		entity->GetRender()->SpoonDraw(WindowRef);
	}
	
	return true;
}

Level* Application::GetWorld() const
{
	return CurrentLevel;
}
