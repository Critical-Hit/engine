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
		buildoptions {"-std=c++11"}
		links {"GL", "sfml-system", "sfml-window", "GLEW"}
	configuration {"macosx", "xcode3"}
		buildoptions {"-std=c++11 -stdlib=c++"}
	configuration {"macosx", "gmake"}
		buildoptions {"-std=c++11"}
	configuration {"windows", "vs2010"}
		links {"OpenGL32"}
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

