#pragma once

#ifdef CGINE_PLATFORM_WINDOWS
	#ifdef CGINE_BUILD_DLL
		#define CGINE_API __declspec(dllexport)
	#else 
		#define CGINE_API __declspec(dllimport)
	#endif
#else
	#error Chronogine currently only supports Windows ! :/
#endif