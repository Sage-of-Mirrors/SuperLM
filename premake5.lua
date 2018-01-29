
-------------------------------------------------------------------------------

workspace "SuperLM"

targetdir "build/bin/%{cfg.platform}-%{cfg.buildcfg}"
objdir "build/obj/%{cfg.platform}-%{cfg.buildcfg}/%{prj.name}"

configurations {
	"Debug",
	"Release",
}

platforms {
	"Windows",
	"Linux",
}

-------------------------------------------------------------------------------

project "SuperLM"
kind "StaticLib"
language "C++"

filter "configurations:Debug"
defines { "SUPERLM_DEBUG" }
symbols "On"

filter "configurations:Release"
defines { "SUPERLM_RELEASE" }
optimize "On"

filter "configurations:Release"
defines { "SUPERLM_RELEASE" }
optimize "On"

filter "action:vs*"
defines { "SUPERLM_VISUAL_STUDIO" }

filter { "platforms:Windows" }
defines { "SUPERLM_WINDOWS" }

filter { "platforms:Linux" }
defines { "SUPERLM_LINUX" }

filter { }

includedirs { "" }

-- windows linking utilities only (put third-party libs/incs in these folders)
includedirs { "dependencies/includes"  }
libdirs     { "dependencies/libraries" }

files {
	"SuperLM/**.h",
	"SuperLM/**.cpp",
}

vpaths {
	["include/*"] = "SuperLM/*.h",
	["source/*"]  = "SuperLM/**.cpp",
}

-------------------------------------------------------------------------------
