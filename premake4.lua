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
        includedirs {"/usr/local/include"}
        libdirs {"/usr/local/lib"}
    configuration {"macosx", "gmake"}
        platforms {"Universal64"}
        buildoptions {"-std=c++11"}
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
    configuration {"windows", "vs2010"}
        platforms {"x64"}
        links {"OpenGL32", "glfw3"}
        includedirs{"core/include"}
        libdirs {"core/lib"}

moduleNames = os.matchdirs("modules/*")
for i = 1,table.getn(moduleNames) do
    moduleNames[i] = string.gsub(moduleNames[i], "modules/", "", 1)
end

for i = 1,table.getn(moduleNames) do
    print(moduleNames[i])
end

for i = 1,table.getn(moduleNames) do
    project (moduleNames[i])
    kind "StaticLib"
    language "C++"
    files {
        "modules/" .. moduleNames[i] .. "/**.h"
    }
    flags {
        "ExtraWarnings"
    }
end

project "Core"
    kind "ConsoleApp"
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
    links {
      --  "Modules",
        "Game",
    }
    --links[2] = moduleNames[1]
    configuration {"macosx", "xcode3"}
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
--[[
project "Modules"
    kind "StaticLib"
    language "C++"
    files {
        "modules/**.h",
        "modules/**.cpp"
    }
    flags {
        "ExtraWarnings"
    }
   ]] 
project "Game"
    kind "StaticLib"
    language "C++"
    files {
        "Game/**.h",
        "Game/**.cpp"
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
    if (table.getn(os.matchfiles("modules/**/*.cpp"))) > 0 then
        links {
            "Modules",
            "Core"
        }
    else
        links {
            "Core"
        }
    end


