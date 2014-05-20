solution "Engine"
	configurations {"Debug", "Release"}
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
		"src/**.h",
		"src/**.cpp"
	}
	flags {
		"ExtraWarnings"
	}
	includedirs {
		"modules/**",
		"/usr/local/include"
	}
	libdirs {
		"/usr/local/lib"
	}
	configuration {"macosx", "xcode3"}
		links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
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

