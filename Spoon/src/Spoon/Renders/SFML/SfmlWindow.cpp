#include "SfmlWindow.h"
#include "Object/SActor.h"
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
	// Tick
	sf::Time time = clock.getElapsedTime();
	clock.restart();
	AppTickEvent TickEvent(time.asSeconds());
	EventCallBack(TickEvent);
}

void SfmlWindow::OnRender()
{
	WindowRef->clear();
	sf::Event event;
	while (WindowRef->pollEvent(event))
	{
		HandleEvent(event);
	}
	
	EventRenderBack();

	WindowRef->display();
}

void SfmlWindow::Draw(const SActor* _currentActor)
{
	if (_currentActor == nullptr)
	{
		return;
	}

	sf::RectangleShape _currentShape;

	_currentShape.setSize(sf::Vector2f(_currentActor->GetSize().X, _currentActor->GetSize().Y));
	std::unique_lock<std::mutex> _lock(_mutex);
	_currentShape.setFillColor(sf::Color(_currentActor->GetColor().R, _currentActor->GetColor().G, _currentActor->GetColor().B, _currentActor->GetColor().A));
	_lock.unlock();
	_currentShape.setPosition(sf::Vector2f(_currentActor->GetLocation().X, _currentActor->GetLocation().Y));

	if (WindowRef != nullptr)
	{
		WindowRef->draw(_currentShape);
	}

	return;
}

unsigned int SfmlWindow::GetWidth() const
{
	return m_Data.Width;
}

unsigned int SfmlWindow::GetHeight() const
{
	return m_Data.Height;
}

void SfmlWindow::Init(const WindowsProps& props)
{
	m_Data.Title = props.Title;
	m_Data.Height = props.Height;
	m_Data.Width = props.Width;

	WindowRef = new sf::RenderWindow(sf::VideoMode(m_Data.Width, m_Data.Height), m_Data.Title);
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
	}
	else if (event.type == sf::Event::Closed)
	{
		WindowCloseEvent tmpevent;
		EventCallBack(tmpevent);
	}
	else if (event.type == sf::Event::Resized)
	{
		WindowResizeEvent tmpevent(event.size.width, event.size.height);
		EventCallBack(tmpevent);
	}
	else if (event.type == sf::Event::MouseMoved)
	{
		MouseMovedEvent tmpevent(FVector2D(event.mouseMove.x, event.mouseMove.y));
		EventCallBack(tmpevent);
	}
	else if (event.type == sf::Event::MouseButtonPressed)
	{
		MouseButtonPressedEvent tmpevent(event.mouseButton.button);
		EventCallBack(tmpevent);
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		MouseButtonReleasedEvent tmpevent(event.mouseButton.button);
		EventCallBack(tmpevent);
	}
	// TODO mettre le reste des events qui pourrais servire ici.
}
