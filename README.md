Critical Hit Game Engine
======

C++ game engine built using [OpenGL](https://www.opengl.org/) and [SFML](http://www.sfml-dev.org/) and available under a permissive licence.

#Build Instructions

Use [premake4](http://industriousone.com/premake) to generate a project file or Makefile and build with your OS-specific tool. We also use [Python 3](http://www.python.org) for some support scripts.

##Windows

Install [Visual Studio Community 2013](http://www.visualstudio.com/downloads/download-visual-studio-vs).

Download [Premake 4.3](http://industriousone.com/premake/download) and extract premake4.exe to `C:\premake4\bin`. 

Add `C:\premake4\bin` to your PATH user environment variable:

1. Type "environment variables" into the Start Menu search menu to access Environment Variables.  
1. If Path already exists in User variables, edit it and add "C:\premake4\bin;" to the front.  If Path doesn't exist, create a new variable with "Path" for the name and "C:\premake4\bin" for the value.

Install [Python 3.0+](https://www.python.org/downloads/windows) and add "C:\PythonXX" to your PATH user environment variable (see above).

OpenGL is statically linked in Visual Studio and SFML is statically linked in the project source, so installing them separately is not required.

Generate the Visual Studio Project and run the build:

1. Open a command prompt and navigate to the directory containing premake4.lua. 
1. Type `premake4 vs2010`. Visual Studio 2010 project files will be generated. 
1. Open the .sln file in Visual Studio 2013. You should be prompted to upgrade the projects to the VS2013 compiler and libraries. Click OK. If you do not see this dialog, you can force it to appear with Project>Retarget Solution.
1. Set the Solution Platforms dropdown to x64.
1. Right-click the Solution in the Solution Explorer and click Build Solution.

##Mac OSX

###Libraries

We highly recommend using [Homebrew](http://www.brew.sh) when developing on Mac OSX. If this is not possible, you can download the required libraries and edit the PATH manually.

####Homebrew

Open a terminal and type `brew install premake sfml`

####Manual Download

If Homebrew is not available, you can manually download add the binary to your path. 

Download [Premake 4.3](http://industriousone.com/premake/download) and extract the binary from the tarball. Move this binary to /opt/premake4/bin.

Open ~/.bash_profile with a text editor and add a line to edit your PATH. For example:

`PATH="/opt/premake4/bin:$PATH"`

You will have to log out and in again to apply this change.

You will then have to install SFML. See [SFML's Download page](http://sfml-dev.org/download/sfml/2.1) for more information.

###Python
Python3 may already be installed. You can check with `python3 --version`. If it is not installed you can install it using Homebrew or download it from [here](https://www.python.org/download/mac).

###Build Tool

You can use either of two options to develop and build: XCode or the command line with GNU Make.

####XCode

Install XCode from the App Store.

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 xcode3`. An XCode project file will be generated. Open it with XCode and run the build.

####GNU Make

Install the Command Line Tools from [developer.apple.com](https://developer.apple.com/downloads/index.action) (Apple Developer account required).

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.

##Linux

Use your distribution's package manager to install the build dependencies:

* GCC or Clang 
* Make
* Premake >= 4.3
* SFML 2.1
* Python >= 3.0

We are compiling in C++11 mode, so recent versions of GCC are preferred. We also assume that you have a GUI and graphics driver installed.

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.
