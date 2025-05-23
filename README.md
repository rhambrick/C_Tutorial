# C Tutorial
This is some example code of core concepts of the C programming language.
I took a crash course on C recently to refresh my memory, pun intended.
This is the code from each chapter that I wrote as I went.
I am not an expert though!
My advice to follow this is to pull the code into a folder on your PC,
then use a code editor like vscode to examine the code and it's plentiful
comments. But also textbooks are about the same in terms of efficiency,
and those are written by actual subject matter experts.

# How to compile
Compiling code is transforming it from human readable / English based code to machine code (1's and 0's) which can be executed on your hardware.
Compilers are software that do this for your specific processor (ex. Intel x86 processors are different architecture from Apple's M chips, so they will need different machine code based on platform).

There's multiple compilers out there for C, but I personally use gcc (the GNU compiler collection) on my Macbook.

## MacOS
To install gcc on Mac, the easiest way is to install homebrew, a package manager that is useful for many other types of software installs. To install homebrew, type the following command into your terminal:

```/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"```

Next, install gcc with homebrew with the following:

```brew install gcc```

You can check if it installed correctly with:

```gcc --version```

After gcc is installed, a comment in the code gives the command for compiling and executing the code. Typically the format is:

```gcc nameOfProgram.c -o nameOfOutputBinaryToExecute -flags or other files needed to compile if necessary```

## Windows
Installing gcc on Windows can be done through the MSYS2 package manager. Download the MSYS2 installer from the official website and follow the installation instructions (https://www.msys2.org/)

Next, run the command

```pacman -S mingw-w64-x86_64-toolchain```

Add the MSYS2 bin directory (e.g., C:\msys64\mingw64\bin) to your system's PATH environment variable (https://stackoverflow.com/questions/5733220/how-do-i-add-the-mingw-bin-directory-to-my-system-path)

After completing the installation and setting the PATH, open a command prompt and type gcc --version to verify that GCC is installed and accessible.
