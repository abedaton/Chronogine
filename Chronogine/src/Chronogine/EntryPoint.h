#pragma once

#ifdef CGINE_PLATFORM_WINDOWS

extern Chronogine::Application* Chronogine::CreateApplication();

int main(int argc, char** argv) {
	Chronogine::Log::Init();
	CGINE_CORE_WARN("Initialized Log!");
	CGINE_INFO("Hello!");


	printf("Chronogine\n");
	auto app = Chronogine::CreateApplication();
	app->Run();
	delete app;
}
#endif