#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ImaginaryEngine
{
	std::shared_ptr<spdlog::logger> Log::_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_CoreLogger = spdlog::stdout_color_mt("IMAGINARYENGINE");
		_CoreLogger->set_level(spdlog::level::trace);
		_ClientLogger = spdlog::stdout_color_mt("APP");
		_ClientLogger->set_level(spdlog::level::trace);
	}
}

