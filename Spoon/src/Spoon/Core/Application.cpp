#include "Application.h"
#include "Level.h"

#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"

#include "Object/SWidget.h"

#include <thread>
#include <mutex>

Application* Application::s_Instance = nullptr;

Application::Application() : WindowName("Spoon Engine"), ScreenSize(FVector2D(1280, 720)), m_WindowRef(nullptr)
{
	s_Instance = this;
	Init();
}

Application::Application(std::string windowName, FVector2D screensize) : WindowName(windowName), ScreenSize(screensize), m_WindowRef(nullptr)
{
	s_Instance = this;
	Init();	
}

Application::~Application()
{
	delete CurrentLevel;
	delete m_WindowRef;
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
	std::thread Graphicthread(std::bind(&Application::GraphicRun, this));
	LogicThread.join();
	Graphicthread.join();
	LogicThread.detach();
	Graphicthread.detach();
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

	dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(Application::OnKeyPressed));

	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

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
		//for (Layer* layer : m_LayerStack)
		//{
		//	layer->OnUpdate();
		//}

		std::mutex _mutex;
		_mutex.lock();
		m_WindowRef->OnUpdate();
		_mutex.unlock();
	}
}

void Application::GraphicRun()
{
	while (bIsRunning)
	{
#ifdef DEBUG
		std::cout << "GraphicRun is running perfectly." << std::endl;
#endif // DEBUG
		std::mutex _mutex;
		_mutex.lock();
		m_WindowRef->OnRender();
		_mutex.unlock();
	}
#ifdef DEBUG
	std::cout << "GraphicRun has perfectly end." << std::endl;
#endif // DEBUG
}

Level* Application::GetWorld() const
{
	return CurrentLevel;
}
