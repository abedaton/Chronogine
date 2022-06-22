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

#ifdef CE_ENABLE_ASSERT
	#define CE_ASSERT(x, ...) { if(!(x)) { CE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CE_CORE_ASSERT(x, ...) { if(!(x)) { CE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else 
	#define CE_ASSERT(x, ...)
	#define CE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)