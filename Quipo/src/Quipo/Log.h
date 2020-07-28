#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Quipo {

	class Log
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

// Core log macros
#define QP_CORE_TRACE(...)   ::Quipo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QP_CORE_INFO(...)    ::Quipo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QP_CORE_WARN(...)    ::Quipo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QP_CORE_ERROR(...)   ::Quipo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QP_CORE_FATAL(...)   ::Quipo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define QP_TRACE(...)   ::Quipo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QP_INFO(...)    ::Quipo::Log::GetClientLogger()->info(__VA_ARGS__)
#define QP_WARN(...)    ::Quipo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QP_ERROR(...)   ::Quipo::Log::GetClientLogger()->error(__VA_ARGS__)
#define QP_FATAL(...)   ::Quipo::Log::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef QP_PLATFORM_LINUX
	#ifdef QP_ENABLE_ASSERTS
		#define QP_ASSERT(x, ...) { if(!(x)) QP_ERROR("Assertion Failed: {0}", __VA_ARGS__); }
		#define QP_CORE_ASSERT(x, ...) { if(!(x)) QP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); }
	#else
		#define QP_ASSERT(x, ...)
		#define QP_CORE_ASSERT(x, ...)
	#endif
#endif
