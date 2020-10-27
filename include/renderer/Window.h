#pragma once

#include "map/Maps.h"
#include "renderer/Renderer.h"
#include "events/ApplicationEvent.h"

class Window
{
public:
	Window(const char* name);
	void Run();
	void OnUpdate(Event& event);
private:
	bool CloseWindow(WindowCloseEvent& event);
private:
	Renderer m_Renderer;
	NewMap test;
	bool m_Running;
};