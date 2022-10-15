#pragma once

#include "Core.h"

namespace ImaginaryEngine
{
	class IMAGINARY_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}



