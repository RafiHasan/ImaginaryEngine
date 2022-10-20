#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace ImaginaryEngine
{
	class IMAGINARY_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> _CoreLogger;
		static std::shared_ptr<spdlog::logger> _ClientLogger;
	};
}
//Core logger macros
#define IWE_CORE_TRACE(...)		::ImaginaryEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IWE_CORE_INFO(...)		::ImaginaryEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IWE_CORE_WARN(...)		::ImaginaryEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IWE_CORE_ERROR(...)		::ImaginaryEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IWE_CORE_FATAL(...)		::ImaginaryEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client logger macros
#define IWE_TRACE(...)			::ImaginaryEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IWE_INFO(...)			::ImaginaryEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define IWEE_WARN(...)			::ImaginaryEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IWE_ERROR(...)			::ImaginaryEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define IWE_FATAL(...)			::ImaginaryEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

