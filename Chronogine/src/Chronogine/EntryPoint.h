#pragma once

#ifdef CGINE_PLATFORM_WINDOWS

extern Chronogine::Application* Chronogine::CreateApplication();

int main(int argc, char** argv) {
	printf("Chronogine\n");
	auto app = Chronogine::CreateApplication();
	app->Run();
	delete app;
}
#endif