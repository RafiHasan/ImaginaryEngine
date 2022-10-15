#pragma once

#ifdef IWE_PLATFORM_WINDOWS

extern ImaginaryEngine::Application* ImaginaryEngine::CreateApplication();

int main(int argc,char** argv)
{
	printf("Engine Started");
	auto app = ImaginaryEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#else
#error IMAGINARY_API only supports windows
#endif // IWE_PLATFORM_WINDOWS	