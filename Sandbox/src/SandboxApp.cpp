#include <Chronogine.h>

class Sandbox : public Chronogine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Chronogine::Application* Chronogine::CreateApplication() {
	return new Sandbox();
}