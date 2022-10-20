#pragma once

#ifdef IWE_PLATFORM_WINDOWS

extern ImaginaryEngine::Application* ImaginaryEngine::CreateApplication();

int main(int argc,char** argv)
{
	ImaginaryEngine::Log::Init();
	IWE_CORE_WARN("Application Started");
	int a = 5;
	IWE_INFO("Welcome {0}",a);
	auto app = ImaginaryEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#else
#error IMAGINARY_API only supports windows
#endif // IWE_PLATFORM_WINDOWS	