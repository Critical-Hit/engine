Game Engine
======

Modular C++ game engine

Build instructions
====
Use [premake4](http://industriousone.com/premake) to generate a project file or Makefile and build with your OS-specific tool.

Windows and Visual Studio
--
Install [Visual Studio Express 2013 for Windows Desktop](http://www.visualstudio.com/downloads/download-visual-studio-vs). Profesional/Premium/Ultimate will also work.

Download [Premake 4.3](http://industriousone.com/premake/download) and extract the premake4 binary to C:\premake4\bin. Add C:\premake4\bin to your PATH user environment variable. (Type "environment variables" into the Start Menu search for quick access.)

Open a command prompt and navigate to the directory containing premake4.lua. Type `premake4 vs2010`. Visual Studio 2010 project files will be generated. Open the .sln file in Visual Studio 2013. You will be prompted to migrate the project to VS2013- click yes.

Mac OSX and XCode or GNU Make
--
Download [Premake 4.3](http://industriousone.com/premake/download) and extract the binary from the tarball. Move this binary to somewhere in your path using a command like `mv ~/Downloads/premake4 /usr/local/bin`.

You can use either of two options to develop, XCode or the command line with GNU Make.

Option 1 (XCode):
Make sure you have XCode installed, if not install it from the Mac App store.

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 xcode3`. An XCode project file will be generated that you can open with XCode.

Option 2 (Command Line):
Make sure you have the OSX command line tools installed, if not download them [here](https://developer.apple.com/downloads/index.action) and install them.

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.

Linux and GNU Make
--
Use your distribution's package manager to install the basic development tools as well as premake.

Debian, Ubuntu, Linux Mint, elementary OS: `sudo aptitude install build-essential premake`

Red Hat, Fedora, CentOS: `sudo yum groupinstall 'Development Tools' && sudo yum install premake`

Arch Linux: `sudo pacman -Syu base-devel premake`

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.
