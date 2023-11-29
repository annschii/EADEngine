#pragma once


#ifdef EAD_PLATFORM_WINDOWS

extern EADEngine::Application* EADEngine::CreateApplication();

int main(int argc, char** argv)
{

	EADEngine::Log::Init();
	EAD_CORE_WARN("Initialized Log!");
	int a = 5;
	EAD_CLIENT_INFO("Hello! Var={0}", a);

	auto app = EADEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // EAD_PLATFORM_WINDOWS
