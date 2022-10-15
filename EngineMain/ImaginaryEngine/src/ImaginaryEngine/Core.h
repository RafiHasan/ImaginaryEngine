#pragma once

#ifdef IWE_PLATFORM_WINDOWS
	#ifdef IWE_BUILD_DLL
		#define IMAGINARY_API _declspec(dllexport)
	#else
		#define IMAGINARY_API _declspec(dllimport)
	#endif // DEBUG
#else
	#error IMAGINARY_API only supports windows
#endif // IWE_PLATFORM_WINDOWS	
