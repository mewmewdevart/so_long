

<p align="center">
  <img src="https://user-images.githubusercontent.com/50052600/224555283-9b0d1dea-97f7-4f58-80fc-600bec04f4d5.gif" alt="Sublime's custom image"/>
</p>

<h1 align="center">
 so_long
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
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements (Version: 2.3). This project uses the 42 school's graphical library, MiniLibX. <br>
This project is not meant to be a fully-fledged game, rather an introduction to a minimal, event-wise graphic library, developed over the course. <br>
<br>
Mandatory part: <br>
- [x] Game actions: <br>
The player can move in four directions but cannot move into walls. To exit the game, the player needs to collect something. The WASD keys are used to move the main character, and the game has a top-down 2D view. The movements are displayed in the shell, and pressing ESC must close the window and quit the program cleanly. <br>
- [x] Graphics actions: <br>
The program should display the image within a window, and window management should be smooth, such as switching to another window or minimizing. Pressing the [ESC] key should close the window and quit the program cleanly. The usage of MiniLibX images is mandatory.
- [x] Map actions:<br>
The map must be rectangular/square in shape, surrounded by walls with a clear path to the exit. It should be able to parse any type of map as long as it follows the aforementioned rules and contains three components - the exit, player start position, and collectibles. Additionally, if there is a misconfiguration in the map, the program should return an error message to indicate the issue.

Bonus part:
- [x] Make the player lose when they touch an enemy patrol.
- [x] Add some sprite animation.
- [x] Display the movement count directly on screen instead of writing it in the shell.

My implementations:
- [x] The name displayed in the executable window shows the name of the game and the name of the map that the person chose to open. (I had to remove this, but you can find it in my commit history)
- [x] Clicking on the cross 'X' on the window's close the game.
- [x] Press 'R' to reset the game.
- [x] Cool design border in the map

## 🧶 Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(Character)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with a error message.

🏆 | The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

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
This project requires the [GNU Compiler Collection](https://gcc.gnu.org/), the [GNU Make](https://www.gnu.org/software/make/) compiler, internet to clone [MiniLibX](https://github.com/42Paris/minilibx-linux#readme) in the libraryfolder and X11 Development Libraries and Headers (`sudo apt-get install libx11-dev`).

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

**1. Run the Game**
```bash
# Use that command to clone the Minilibx inside the libs/ folder
$ make call_mlx

# Run the command make root directory to run the mandatory part
$ make

# This command compiles the executable file 'so_long' and runs it along with any map
# of your choice (or a custom one) located in the directory 'rscs/maps'.
#	To execute it, run the following command:
$ ./bin/so_long ./rscs/maps/valids/map_valid_rectangle.ber
# If you want to run the bonus part, run the 'make bonus' command in your directory
#	and provide the correct path to the files starting with ./bin/so_long bonus
```
**2. How to play**
- Control the player using the arrow keys (up, down, left, and right) or the letter keys (w, a, s, and d).
- Press the 'R' key on your keyboard to reset the current level.
- Press the [ESC] key or Click in the 'X' window to exit the game.

<p align="center">
  <img src="https://user-images.githubusercontent.com/50052600/232246726-d4a89f87-0bbc-4d43-9e13-8e58c54579b1.png" alt="Gameplay Screen"/>
</p>


<p align="center">
	<a href="https://www.youtube.com/watch?v=tNngHctUoaY">Click here to watch the video</a> 
</p>


## 🗺️ Create your own Map:
For curious minds who want to test the project's features: <br>
- Create a new text file with a .ber extension. This will be your map file.
- Open the text file in a text editor.
- Define the map dimensions using this 5 symbols to represent different elements on the map:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit,
	- P for the player’s starting position.

- Create a rectangular or square map, knowing that the map must be surrounded by '1's (walls) and must contain only one 'P' (player's starting point), one 'E' (exit), and multiple 'C's (collectibles). To test all the game features and have a better gaming experience, create a good level design using other game objects such as '0' for empty spaces (where the player can move).
- After creating the map, you can run it by passing the path of 'bin/so_long' and the path where the map was created:
```
$ ./bin/so_long map_example.ber
```

## 🦾 Technologies
- [VS CODE](https://www.eclipse.org/downloads/) |  I'm a fan of Vim but due to the size of the project, I opted to use Vscode.
- [GNU Compiler Collection](https://gcc.gnu.org/) | A suite of programming language compilers developed by the GNU Project for C, C++, Objective-C, Fortran, Ada, and other languages
- [GNU Make](https://www.gnu.org/software/make/) | A build automation tool for compiling and linking software projects
- [MiniLibX](https://github.com/42Paris/minilibx-linux#readme) | A simple X-Window System library for graphics programming
- A classic notebook to take some notes about the project

## 🔗 References
- [Markdown](https://www.markdownguide.org/basic-syntax/) | Documentation on how to use Markdown.
- Internet forums and blogs to address my doubts related to the language (Alura, Stack Overflow, and Geeks for Geeks).
- Google Translate to translate some parts of content that were in another language.
- 42SP Cadets and others so_longs projects | :)

## 📜  License
This project is licensed under the terms of the [LICENSE](https://github.com/mewmewdevart/so_long/blob/main/LICENSE) file. See the file for more details. <br>

<p align="center"> Developed with love 💜 by Larissa Cristina Benedito (Mewmew/Larcrist). </p>
