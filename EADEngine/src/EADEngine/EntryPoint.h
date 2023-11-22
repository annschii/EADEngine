#pragma once


#ifdef EAD_PLATFORM_WINDOWS

extern EADEngine::Application* EADEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("EADEngine");
	auto app = EADEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif // EAD_PLATFORM_WINDOWS
