#include "SfmlWindow.h"


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
	sf::Event event;
	while (WindowRef->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			EventCallBack();
		}
	}
	WindowRef->clear();
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