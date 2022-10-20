workspace "EngineMain"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ImaginaryEngine"
	location "ImaginaryEngine"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
		"IWE_BUILD_DLL",
		"IWE_PLATFORM_WINDOWS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/SandBox")
		}

	filter "configurations:Debug"
		defines "IME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IME_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "IME_DISTRIBUTION"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ImaginaryEngine/vendor/spdlog/include",
		"ImaginaryEngine/src"
	}

	links
	{
		"ImaginaryEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
		"IWE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IME_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IME_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "IME_DISTRIBUTION"
		optimize "On"
