#include "pch.h"

#include "application/Application.h"
#include "utils/Timer.h"
#include "ui/Text.h"
#include "entity/TestAnimable.h"
#include "ui/Button.h"

Application::Application()
	: Context(SDL_INIT_EVERYTHING), EventListener(this), m_Window(&m_CurrentState), m_CurrentState(ApplicationState::Game), m_Map(), m_Running(true)
{
}

void Application::handle()
{
	switch (m_Action)
	{
		case Action::OpenMenu:
			std::cout << "Open Menu" << std::endl;
			break;
		case Action::Quit:
			m_Running = false;
			return;
	}
	switch (m_CurrentEvent->type)
	{
		case SDL_EventType::SDL_QUIT:
			m_Running = false;
			return;
		case SDL_EventType::SDL_WINDOWEVENT:
			if (m_CurrentEvent->window.event == SDL_WINDOWEVENT_RESIZED) {
				m_Window.SetSize({m_CurrentEvent->window.data1, m_CurrentEvent->window.data2});
				return;
			}
	}
}

void Application::loop()
{
	Text text(Position<float>{0, 0}, Dimension<float>{5, 5}, "Hello World !", TTF_OpenFont("assets/font/arial/arial.ttf", 10));
	Timer::Init(60);
	while (m_Running)
	{
		EventListener::Update();
		m_Map.Tick();
		m_Window.Render();
		// text.SetText(std::to_string(Timer::getFps()));
		Timer::waitForNextFrame();
	}
}
