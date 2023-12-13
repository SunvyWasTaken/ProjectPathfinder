#include "Application.h"
#include "Level.h"

#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"
#include "Spoon/Renders/SFML/SfmlObject.h"

Application::Application() : WindowName("Spoon Engine"), ScreenSize(FVector2D(1280, 720))
{
	Init();
}

Application::Application(std::string windowName, FVector2D screensize) : WindowName(windowName), ScreenSize(screensize)
{
	Init();
}

Application::~Application()
{
	delete CurrentLevel;
}

void Application::Init()
{
	WindowsProps win(WindowName, ScreenSize.X, ScreenSize.Y);
	WindowRef = Window::Create(win);
	WindowRef->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

	CurrentLevel = new Level();
}

void Application::Run()
{
	while (bIsRunning)
	{
		for (Layer* layer : m_LayerStack)
		{
			layer->OnUpdate();
		}
		WindowRef->OnUpdate();
	}
}

void Application::OnEvent(SpoonEvent& e)
{
	EventDispatcher dispatcher(e);

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
		if (e.Handle)
			break;
	}

	dispatcher.Dispatch<AppTickEvent>(BIND_EVENT_FN(Application::OnAppTick));
	if(e.Handle)
		return;
	dispatcher.Dispatch<AppRenderEvent>(BIND_EVENT_FN(Application::OnRender));
	if (e.Handle)
		return;
	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));
	if (e.Handle)
		return;
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
	if (e.Handle)
		return;
}

void Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
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
	CurrentLevel->UpdateEntity(e.GetDeltaTime());
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

bool Application::OnWindowResize(WindowResizeEvent& e)
{
	return true;
}

Level* Application::GetWorld() const
{
	return CurrentLevel;
}
