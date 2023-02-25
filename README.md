<h1 align="center">
 so_long  (⚠️ in development)
</h1>

<p align="center">
	<b><i>And thanks for all the fish!</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/mewmewdevart/so_long?color=6272a4" />
	<img alt="Main language" src="https://img.shields.io/github/languages/top/mewmewdevart/so_long?color=6272a4"/>
	<img alt="License" src="https://img.shields.io/github/license/mewmewdevart/so_long?color=6272a4"/>
</p>

## 💡 About the project
> _This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements (Version: 2.3). This project uses the 42 school's graphical library, MiniLibX. <br>
> _This project is not meant to be a fully-fledged game, rather an introduction to a minimal, event-wise graphic library, developed over the course.

## 📁 Structure/
* ```include/```  The header file of the so_long project.
* ```bin/```  Where the final executable binary file goes.
* ```libs/```  The libraries (my own libft + minilibx, which you have to clone).
* ```objs/``` Keeps all the .o files produced throughout the compilation process.
* ```rscs/```  All sprites used in the game in .xpm format + some maps (for running and testing the game).
* ```srcs/```  Where the artcode happens!<br>

## 🛠️ Usage

### Prerequisites

**Linux and MacOS**
This project requires the [GNU Compiler Collection](https://gcc.gnu.org/), the [GNU Make](https://www.gnu.org/software/make/) compiler, and the Internet to clone [MiniLibX](https://github.com/42Paris/minilibx-linux#readme) in the libraryfolder.

**Windows**

You'll need to install Xserver in your machine seeing as the library runs on X-Window system. You may also use WSL on Windows 11 and run ```wsl --update``` and you should be good to go. <br>
❗️| Make sure you have all the required tools installed on your local machine, then continue with these steps.<br>

### Instructions to run the game :

**0. Download the archives**

```bash
# Clone the repository
$ git clone git@github.com:mewmewdevart/so_long.git

# Enter into the directory
$ cd so_long/
```

**1. Running the Game**
```bash
# Use that command to clone the Minilibx inside the libs/ folder
$ make call_mlx

# Run the command make root directory
$ make

# This will compile the executable file so_long to execute its necessary run the archive
# 		+ any map of your choice (or you could even make a map of your own)
$ ./bin/so_long ./rcsc/map.ber
```
**2. How to play**

//soon

### Create your own Map
🗺️ | Bonus for curious minds who want to test the project's features <br>

//soon

## 🍜  License
This project is licensed under the terms of the [LICENSE](https://github.com/mewmewdevart/so_long/blob/main/LICENSE) file. See the file for more details. <br>

<p align="center"> Developed with love 💜 by Larissa Cristina Benedito (Mewmew/Larcrist). </p>
