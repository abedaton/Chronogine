#include "cepch.h"
#include "Application.h"

#include "Chronogine/Events/ApplicationEvent.h"
#include "Chronogine/Log.h"

namespace Chronogine {
	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application(){}

	void Application::Run() {

		while (m_Running){
			m_Window->OnUpdate();
		}
	}
}