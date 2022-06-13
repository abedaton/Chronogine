#include "Application.h"

#include "Chronogine/Events/ApplicationEvent.h"
#include "Chronogine/Log.h"

namespace Chronogine {
	Application::Application(){}

	Application::~Application(){}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			CGINE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput)) {
			CGINE_TRACE(e);
		}

		while (true){}
	}
}