#include "SfmlWindow.h"
#include "Spoon/Events/KeyEvent.h"
#include "Spoon/Events/ApplicationEvent.h"
#include "Spoon/Events/MouseEvent.h"

// Function call de maniere indirect lorsque j'ai besoin de la fenetre.
Window* Window::Create(const WindowsProps& props)
{
	return new SfmlWindow(props);
}

// Creation d'une nouvelle fenetre call init page
SfmlWindow::SfmlWindow(const WindowsProps& props)
{
	Init(props);
}

SfmlWindow::~SfmlWindow()
{
	Shutdown();
}

void SfmlWindow::OnUpdate()
{
	WindowRef->clear();
	sf::Event event;
	while (WindowRef->pollEvent(event))
	{
		HandleEvent(event);
	}
	// Tick
	sf::Time time = clock.getElapsedTime();
	clock.restart();
	AppTickEvent TickEvent(time.asSeconds());
	EventCallBack(TickEvent);
	// Puis render des items.
	AppRenderEvent RenderEvent;
	EventCallBack(RenderEvent);

	// Enfin display them all.
	WindowRef->display();
}

unsigned int SfmlWindow::GetWidth() const
{
	return m_Data.Width;
}

unsigned int SfmlWindow::GetHeight() const
{
	return m_Data.Height;
}

void SfmlWindow::Draw(sf::Shape& currentShape)
{
	WindowRef->draw(currentShape);
}

void SfmlWindow::Init(const WindowsProps& props)
{
	m_Data.Title = props.Title;
	m_Data.Height = props.Height;
	m_Data.Width = props.Width;

	// Create SFML window.
	WindowRef = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_Data.Width, m_Data.Height), m_Data.Title);
}

void SfmlWindow::Shutdown()
{
	WindowRef->close();
}

void SfmlWindow::HandleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		KeyPressedEvent tmpevent(event.key.scancode);
		EventCallBack(tmpevent);
		return;
	}
	if (event.type == sf::Event::Closed)
	{
		WindowCloseEvent tmpevent;
		EventCallBack(tmpevent);
		return;
	}
	if (event.type == sf::Event::Resized)
	{
		WindowResizeEvent tmpevent(event.size.width, event.size.height);
		EventCallBack(tmpevent);
	}
	if (event.type == sf::Event::MouseMoved)
	{
		MouseMovedEvent tmpevent(event.mouseMove.x, event.mouseMove.y);
		EventCallBack(tmpevent);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		MouseButtonPressedEvent tmpevent(event.mouseButton.button);
		EventCallBack(tmpevent);
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		MouseButtonReleasedEvent tmpevent(event.mouseButton.button);
		EventCallBack(tmpevent);
	}
	// TODO mettre le reste des events qui pourrais servire ici.
}
