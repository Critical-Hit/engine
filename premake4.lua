solution "Engine"
    configurations {"Debug", "Release"}
    -- Debug flags
    configuration "Debug"
        flags {"ExtraWarnings", "Symbols"}
        targetdir ("bin/debug")

    -- Release Flags
    configuration "Release"
        flags {"ExtraWarnings", "Optimize"}
        targetdir ("bin/release")

    -- Linux + Make
    configuration {"linux", "gmake" }
        platforms {"x64"}
        buildoptions {"-std=c++11"}
        links {"GL", "glfw", "soil2-linux"}

    -- Max OSX, all build tools
    configuration {"macosx"}
        platforms {"Universal64"}
        buildoptions {"-std=c++11"}
        links {
            "OpenGL.framework",
            "Cocoa.framework", 
            "IOKit.framework", 
            "CoreVideo.framework", 
            "glfw3", 
            "soil2-mac"
        }

    -- Mac OSX + XCode
    configuration {"macosx", "xcode3"}
        includedirs {"/usr/local/include"}
        libdirs {"/usr/local/lib"}

    -- Mac OSX + Make
    configuration {"macosx", "gmake"}
        -- Nothing specific here... yet!

    -- Windows + Visual Studio
    configuration {"windows", "vs2010"}
        platforms {"x64"}
        links {"OpenGL32", "glfw3"}
		includedirs { "core/include" }
    configuration {"windows", "vs2010", "Debug"}
        -- // TODO: Build warning 'LINK : warning LNK4098: defaultlib 'MSVCRT' conflicts with use of other libs; use /NODEFAULTLIB:library'
        links {"soil2-windows-debug"}
    configuration {"windows", "vs2010", "Release"}
        links {"soil2-windows-release"}

project "Core"
    kind "ConsoleApp"
    language "C++"
    files {
        "core/src/**.h",
        "core/src/**.cpp"
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

    configuration {"macosx", "xcode3"}
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
 
 moduleNames = os.matchdirs("modules/*")
for i = 1,table.getn(moduleNames) do
    moduleNames[i] = string.gsub(moduleNames[i], "modules/", "", 1)
end

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