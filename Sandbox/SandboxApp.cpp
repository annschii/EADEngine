#include <EADEngine.h>

class Sandbox : public EADEngine::Application 
{

public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};


EADEngine::Application* EADEngine::CreateApplication()
{
	return new Sandbox();
}