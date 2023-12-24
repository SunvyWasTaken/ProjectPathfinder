#include "Application.h"
#include "Level.h"

#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"

Application* Application::s_Instance = nullptr;

Application::Application() : WindowName("SpoonEngine"), ScreenSize(FVector2D(720, 1080))
{
	s_Instance = this;
	Init();
	
}

Application::Application(std::string windowName, FVector2D screensize) : WindowName(windowName), ScreenSize(screensize)
{
	s_Instance = this;
	Init();
}

Application::~Application()
{
	delete CurrentLevel;
}

void Application::Init()
{
	WindowsProps win(WindowName, ScreenSize.X, ScreenSize.Y);
	m_WindowRef = Window::Create(win);
	m_WindowRef->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	m_WindowRef->SetEventRenderBack(std::bind(&Application::OnRender, this));

	CurrentLevel = new Level();
}

void Application::Run()
{
	std::thread LogicThread(std::bind(&Application::TickRun, this));
	LogicThread.detach();
	while (bIsRunning)
	{
		m_WindowRef->OnRender();
	}
}

void Application::OnEvent(SpoonEvent& e)
{
	EventDispatcher dispatcher(e);

	dispatcher.Dispatch<AppTickEvent>(BIND_EVENT_FN(Application::OnAppTick));

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
#if DEBUG
	std::cout << e.ToString() << std::endl;
#endif // DEBUG

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

void Application::OnRender()
{
	for (SActor* CurrentActor : GetWorld()->GetEntityList())
	{
		m_WindowRef->Draw(CurrentActor);
	}
	return;
}

bool Application::OnWindowResize(WindowResizeEvent& e)
{
	return true;
}

void Application::TickRun()
{
	while (bIsRunning)
	{
		m_WindowRef->OnUpdate();
	}
}

Level* Application::GetWorld() const
{
	return CurrentLevel;
}
