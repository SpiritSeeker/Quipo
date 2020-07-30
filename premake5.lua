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
IncludeDir["Glad"] = "Quipo/vendor/Glad/include"
IncludeDir["glm"] = "Quipo/vendor/glm"
IncludeDir["stb_image"] = "Quipo/vendor/stb_image"

include "Quipo/vendor/GLFW"
include "Quipo/vendor/Glad"

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
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h"
	}

  includedirs
  {
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
  }

	links
	{
		"GLFW",
		"Glad"
	}

	defines
	{
		"GLFW_INCLUDE_NONE"
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
		"Quipo/vendor/spdlog/include",
		"%{IncludeDir.glm}"
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
