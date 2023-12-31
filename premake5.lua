workspace "EADEngine"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "EADEngine/vendor/GLFW/include"

include "EADEngine/vendor/GLFW"

project "EADEngine"
	location "EADEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "eadpch.h"
	pchsource "EADEngine/src/eadpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"openg132.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EAD_PLATFORM_WINDOWS",
			"EAD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.."/Sandbox")
		}


	filter "configurations:Debug"
		defines "EAD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EAD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EAD_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"EADEngine/vendor/spdlog/include",
		"EADEngine/src"
	}

	links
	{
		"EADEngine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EAD_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "EAD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EAD_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EAD_DIST"
		optimize "On"