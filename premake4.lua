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
		links {"libgl"}
	configuration {"macosx", "xcode3"}
		buildoptions {"-std=c++11 -stdlib=c++"}
	configuration {"macosx", "gmake"}
		buildoptions {"-std=c++11 -stdlib=c++"}
	configuration {"windows", "vs2010"}
		-- todo force c++11

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

