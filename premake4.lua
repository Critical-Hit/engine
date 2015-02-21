solution "Engine"
    -- Specify debug and release builds
    configurations {"Debug", "Release"}
    configuration "Debug"
        flags {"Symbols", "ExtraWarnings"}
        targetdir ("bin/debug")
    configuration "Release"
        flags {"Optimize", "ExtraWarnings"}
        targetdir ("bin/release")
    -- specify OS/build tool options
    -- Linux
    configuration {"linux", "gmake" }
        platforms {"x64"}
        buildoptions {"-std=c++11"}
        includedirs {"core/include"}
        links {
            "GL", 
            "sfml-audio",
            "sfml-graphics",
            "sfml-network",
            "sfml-system",
            "sfml-window",
	    "soil2-linux"
        }
    -- Mac OSX
    configuration {"macosx"}
        platforms {"Universal64"}
        buildoptions {"-std=c++11"}
        includedirs {"core/include", "/usr/local/include"}
        libdirs {"core/lib", "/usr/local/lib"}
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
    -- Windows
    configuration {"windows", "vs2010"}
        platforms {"x64"}
        links {"OpenGL32"}
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

-- Detect modules
moduleNames = os.matchdirs("modules/*")
for i = 1,table.getn(moduleNames) do
    moduleNames[i] = string.gsub(moduleNames[i], "modules/", "", 1)
end

-- Engine
project "Core"
    kind "WindowedApp"
    language "C++"
    files {
        "core/src/**.h",
        "core/src/**.cpp"
    }
    includedirs {
        "core/include",
        "core/src",
        "core/src/**",
        "game/src",
        "game/src/**",
        "modules/*/src/**"
    }
    libdirs {
        "core/lib"
    }
    links {"Game"}
    configuration {"macosx"}
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

-- Game
project "Game"
    kind "StaticLib"
    language "C++"
    files {
        "game/**.h",
        "game/**.cpp"
    }
    includedirs {
        "game/include",
        "core/src",
        "core/src/**",
        "game/src",
        "game/src/**",
        "modules/*/src/**"
    }
    libdirs {
        "game/lib"
    }
    -- Link game and modules
    for i = 1,table.getn(moduleNames) do
        links {moduleNames[i]}
    end

-- Modules
for i = 1,table.getn(moduleNames) do
    project (moduleNames[i])
        kind "StaticLib"
        language "C++"
        includedirs {"modules/**"}
        files {
            "modules/" .. moduleNames[i] .. "/src/**.h",
            "modules/" .. moduleNames[i] .. "/src/**.cpp"
        }
end

if _ACTION == "clean" then
    if os.get() == "windows" then
        os.execute("python scripts/clean.py")
    else
        os.execute("python3 scripts/clean.py")
    end
end
