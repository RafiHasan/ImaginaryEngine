#include <ImaginaryEngine.h>

class SandBox:public ImaginaryEngine::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

ImaginaryEngine::Application* ImaginaryEngine::CreateApplication()
{
	return new SandBox();
}