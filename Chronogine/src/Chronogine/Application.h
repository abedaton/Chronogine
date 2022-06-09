#pragma once

#include "Core.h"

namespace Chronogine {

	class CGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	// To be defined in Client
	Application* CreateApplication();
}