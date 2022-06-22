workspace "Chronogine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relatives to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Chronogine/vendor/GLFW/include"

include "Chronogine/vendor/GLFW"


project "Chronogine"
	location "Chronogine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	runtime "Release"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cepch.h"
	pchsource "Chronogine/src/cepch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CGINE_PLATFORM_WINDOWS",
			"CGINE_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CGINE_DEBUG"
		symbols "On"	

	filter "configurations:Release"
		defines "CGINE_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "CGINE_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	links{
		"Chronogine"
	}

	includedirs {
		"Chronogine/vendor/spdlog/include",
		"Chronogine/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"CGINE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CGINE_DEBUG"
		symbols "On"	

	filter "configurations:Release"
		defines "CGINE_RELEASE"
		optimize "On"	
	
	filter "configurations:Dist"
		defines "CGINE_DIST"
		optimize "On"