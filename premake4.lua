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
        links {
            "GL", 
            "sfml-audio",
            "sfml-graphics",
            "sfml-network",
            "sfml-system",
            "sfml-window",
	        "soil2-linux"
        }
    configuration {"macosx"}
        platforms {"Universal64"}
        buildoptions {"-std=c++11"}
        links {
            "OpenGL.framework", 
            "Cocoa.framework", 
            "IOKit.framework", 
            "CoreVideo.framework", 
            "sfml-audio",
            "sfml-graphics",
            "sfml-network",
            "sfml-system",
            "sfml-window",
    	    "soil2-mac" 
        }
    configuration {"macosx", "xcode3"}
        includedirs {"/usr/local/include"}
        libdirs {"/usr/local/lib"}
    configuration {"macosx", "gmake"}
        -- Nothing here yet
    configuration {"windows", "vs2010"}
        platforms {"x64"}
        includedirs{"core/include"}
        libdirs {"core/lib"}
        links { "OpenGL32" }
    configuration {"windows", "vs2010", "Release"}
        links {
            "sfml-main",
            "sfml-audio",
            "sfml-graphics",
            "sfml-network",
            "sfml-system",
            "sfml-window",
	        "soil2-windows-release"
        }
    configuration {"windows", "vs2010", "Debug"}
        links {
            "sfml-main-d",
            "sfml-audio-d",
            "sfml-graphics-d",
            "sfml-network-d",
            "sfml-system-d",
            "sfml-window-d",
	        "soil2-windows-debug"
        }

moduleNames = os.matchdirs("modules/*")
for i = 1,table.getn(moduleNames) do
    moduleNames[i] = string.gsub(moduleNames[i], "modules/", "", 1)
end

project "Core"
    kind "WindowedApp"
    language "C++"
    files {
        "core/src/**.h",
        "core/src/**.cpp"
    }
    flags {
        "ExtraWarnings"
    }
    includedirs {
        "core/include",
        "**/src",
        "**/src/**",
        "modules/*/src/**"
    }
    libdirs {
        "core/lib"
    }
    links {"Game"}

project "Game"
    kind "StaticLib"
    language "C++"
    files {
        "game/**.h",
        "game/**.cpp"
    }
    includedirs {
        "game/include",
        "**/src/**",
        "**/src",
        "modules/*/**",
    }
    libdirs {
        "game/lib"
    }
	for i = 1,table.getn(moduleNames) do
        links {moduleNames[i]}
    end

for i = 1,table.getn(moduleNames) do
    project (moduleNames[i])
    kind "StaticLib"
    language "C++"
    includedirs {
	   "modules/**"
    }
    files {
		"modules/" .. moduleNames[i] .. "/src/**.h",
		"modules/" .. moduleNames[i] .. "/src/**.cpp"
    }
    flags {
        "ExtraWarnings"
    }
end


