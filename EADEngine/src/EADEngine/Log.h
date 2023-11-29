#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace EADEngine {
	class EADEngine_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

//Core log macros
#define EAD_CORE_INFO(...)			::EADEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EAD_CORE_TRACE(...)			::EADEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EAD_CORE_WARN(...)			::EADEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EAD_CORE_ERROR(...)			::EADEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EAD_CORE_FATAL(...)			::EADEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define EAD_CLIENT_INFO(...)		::EADEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define EAD_CLIENT_TRACE(...)		::EADEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EAD_CLIENT_WARN(...)		::EADEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EAD_CLIENT_ERROR(...)		::EADEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define EAD_CLIENT_FATAL(...)		::EADEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)