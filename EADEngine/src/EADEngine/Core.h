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
