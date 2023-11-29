#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace EADEngine {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			EAD_CLIENT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			EAD_CLIENT_TRACE(e);
		}

		while (true);
	}


}