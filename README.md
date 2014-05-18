Game Engine
======

Modular C++ game engine

Build instructions
====
Use [premake4](http://industriousone.com/premake) to generate a project file or Makefile and build with your OS-specific tool.

Windows and Visual Studio
--
Install [Visual Studio Express 2013 for Windows Desktop](http://www.visualstudio.com/downloads/download-visual-studio-vs). Profesional/Premium/Ultimate will also work.

Download [Premake 4.3](http://industriousone.com/premake/download) and extract the premake4 exe to C:\premake4\bin. Add C:\premake4\bin to your PATH user environment variable. Type "environment variables" into the Start Menu search menu to access it.  In user environment variables, if Path already exists, add "C:\premake4\bin" separated with a semi colon.  If it doesn't exist, create a new variable with "Path" for the name and "C:\premak4\bin" for the value.

Open a command prompt and navigate to the directory containing premake4.lua. Type `premake4 vs2010`. Visual Studio 2010 project files will be generated. Open the .sln file in Visual Studio 2013. You will be prompted to migrate the project to VS2013- click yes.

Mac OSX and XCode or GNU Make
--
Install Premake 4.3 using [Homebrew](http://www.brew.sh) or [MacPorts](http://www.macports.com). If this is not possible, you can manually add the binary to your path. Download [Premake 4.3](http://industriousone.com/premake/download) and extract the binary from the tarball. Move this binary to `/opt/premake4/bin`. Open ~/.bash_profile with a text editor and add a line to edit your PATH. For example:

    PATH="/opt/premake4/bin:$PATH"

You will have to log out and in again to apply this change.

You can use either of two options to develop, XCode or the command line with GNU Make.

XCode
#
Install XCode from the App Store.

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 xcode3`. An XCode project file will be generated. Open it with XCode

GNU Make
#
Install the Command Line Tools from [developer.apple.com](https://developer.apple.com/downloads/index.action) (Apple Developer account required).

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.

Linux and GNU Make
--
Use your distribution's package manager to install the basic development tools as well as premake.

Debian, Ubuntu, Linux Mint, elementary OS: `sudo aptitude install build-essential premake`

Red Hat, Fedora, CentOS: `sudo yum groupinstall 'Development Tools' && sudo yum install premake`

Arch Linux: `sudo pacman -Syu base-devel premake`

Open a terminal and navigate to the directory containing premake4.lua. Type `premake4 gmake`. A Makefile will be generated. Type `make help` for usage information, or simply `make` to run the default debug build.
