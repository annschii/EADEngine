#pragma once

#ifdef EAD_PLATFORM_WINDOWS
	#ifdef EAD_BUILD_DLL
		#define EADEngine_API __declspec(dllexport)
	#else 
		#define EADEngine_API __declspec(dllimport)
	#endif // EAD_BUILD_DLL
#else
	#error EADEngine only supports Windows
#endif // EAD_PLATFORM_WINDOWS

#ifdef EAD_ENABLE_ASSERTS
	#define EAD_ASSERTS(x, ...) {if(!(x)){EAD_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define EAD_CORE_ASSERTS(x, ...) {if(!(x)){EAD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define EAD_ASSERT(x, ...)
	#define EAD_CORE_ASSERT(x, ...)
#endif // EAD_ENABLE_ASSERTS


#define BIT(x) (1 << x)