#pragma once


#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Chronogine {
	class CGINE_API Log {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define CGINE_CORE_TRACE(...) ::Chronogine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CGINE_CORE_INFO(...)  ::Chronogine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CGINE_CORE_WARN(...)  ::Chronogine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CGINE_CORE_ERROR(...) ::Chronogine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CGINE_CORE_FATAL(...) ::Chronogine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CGINE_TRACE(...)      ::Chronogine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CGINE_INFO(...)       ::Chronogine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CGINE_WARN(...)       ::Chronogine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CGINE_ERROR(...)      ::Chronogine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CGINE_FATAL(...)      ::Chronogine::Log::GetClientLogger()->fatal(__VA_ARGS__)