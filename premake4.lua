solution "Engine"
	configurations {"Debug", "Release"}
	platforms ("native", "Universal")
	configuration "Debug"
		flags {"Symbols"}
		targetdir ("bin/debug")
	configuration "Release"
		flags {"Optimize"}
		targetdir ("bin/release")
	configuration {"linux", "gmake" }
		platforms {"x64"}
		buildoptions {"-std=c++11"}
		links {"GL", "glfw"}
	configuration {"macosx", "xcode3"}
		platforms {"Universal64"}
		buildoptions {"-std=c++11"}
		links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
	configuration {"macosx", "gmake"}
		platforms {"Universal64"}
		buildoptions {"-std=c++11"}
		links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
	configuration {"windows", "vs2010"}
		platforms {"x64"}
		links {"OpenGL32", "glfw3"}
		libdirs {"lib"}
		includedirs {"include"}
project "Core"
	kind "ConsoleApp"
	language "C++"
	files {
		"src/core/*.h",
		"src/core/*.cpp"
	}
	flags {
		"ExtraWarnings"
	}
  includedirs "modules/**"
  links {
    "Modules"
  }

project "Modules"
  kind "StaticLib"
  language "C++"
  files {
    "modules/**.h",
    "modules/**.cpp"
  }

