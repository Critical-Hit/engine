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
        includedirs {"/usr/local/include", "include"}
        libdirs {"/usr/local/lib", "lib"}
    configuration {"macosx", "gmake"}
        platforms {"Universal64"}
        buildoptions {"-std=c++11"}
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}
    configuration {"windows", "vs2010"}
        platforms {"x64"}
        links {"OpenGL32", "glfw3"}
        includedirs{"include"}
        libdirs {"lib"}

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
        "src/**",
        "modules/**"
    }
    if (table.getn(os.matchfiles("modules/**/*.cpp"))) > 0 then
        links {
            "Modules"
        }
    end
    configuration {"macosx", "xcode3"}
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreVideo.framework", "glfw3"}

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
    
