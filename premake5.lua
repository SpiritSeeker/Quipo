workspace "Quipo"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	platforms
	{
		"linux"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Quipo/vendor/GLFW/include"

include "Quipo/vendor/GLFW"

project "Quipo"
	location "Quipo"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	warnings "Default"
	-- warnings can take the values "Off", "Default", "Extra"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qppch.h"
	pchsource "Quipo/src/qppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

  includedirs
  {
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
  }

	links
	{
		"GLFW"
	}

	filter "system:linux"
		kind "SharedLib"

		links
		{
			"dl",
			"pthread"
		}

		defines
		{
			"QP_PLATFORM_LINUX",
		}

	filter "configurations:Debug"
		defines "QP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QP_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Quipo/src",
		"Quipo/vendor/spdlog/include"
	}

	links
	{
		"Quipo"
	}

	filter "system:linux"

		defines
		{
			"QP_PLATFORM_LINUX",
		}

	filter "configurations:Debug"
		defines "QP_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QP_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QP_DIST"
		runtime "Release"
		optimize "on"
