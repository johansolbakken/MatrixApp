-- Premake.lua
workspace "MatrixApp"
    architecture "x64"
    startproject "matrixapp"
    configurations { 
        "Debug", 
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
--IncludeDir["GLFW"] = "Hazel/vendor/glfw/include"
--IncludeDir["Glad"] = "Hazel/vendor/glad/include"
--IncludeDir["imgui"] = "Hazel/vendor/imgui"
--IncludeDir["glm"] = "Hazel/vendor/glm"
--IncludeDir["spdlog"] = "Hazel/vendor/spdlog/include"

--[[
    MATRIXUTIL PROJECT
]]
project "matrixutil"
    location "matrixutil" -- Path of project
	kind "StaticLib" -- Dynamic library
    language "C++" -- Language of project
    cppdialect "C++17"
    staticruntime "On"
    
    -- Output for Lib
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    -- Output for intermediate files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- Project files
    files { 
        "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.h" 
    }

    includedirs {
        "%{prj.name}/src"
    }

    -- Libraries
	sysincludedirs {
    }

    -- Configuration setup
    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

--[[
    MATRIXUTIL PROJECT
]]
project "gauss"
    location "gauss" -- Path of project
	kind "StaticLib" -- Dynamic library
    language "C++" -- Language of project
    cppdialect "C++17"
    staticruntime "On"
    
    -- Output for Lib
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")

    -- Output for intermediate files
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- Project files
    files { 
        "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.h" 
    }

    links { "matrixutil" }

    includedirs {
        "%{prj.name}/src"
    }

    -- Libraries
	sysincludedirs {
        "matrixutil/src"
    }

    -- Configuration setup
    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

--[[
    Sandbox PROJECT
]]
project "matrixapp"
    location "matrixapp"
	kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"
    
    -- Intermediate and target dirs
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.hpp", "%{prj.name}/src/**.h" }

	sysincludedirs { 
        "gauss/src",
        "matrixutil/src"
    }

    includedirs {
        "%{prj.name}/src"
    }

	links { "gauss", "matrixutil" }

	filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "On"
