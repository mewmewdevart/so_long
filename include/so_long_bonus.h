#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include "custom_letters_bonus.h"
# include <fcntl.h> // Read
# include <string.h> // Strerror

// GAME OBJECTS KEYS
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'
# define ENEMY 'I'

// GAME KEYWORDS
# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 32

// OBJECTS : IMAGES
typedef struct s_game_objs
{
    void	*player;
    void	*player_left;
    void	*player_right;
    void	*player_down;
    void	*player_up;
    void	*collectible;
    void	*exit_open;
    void	*exit_close;
	void	*enemy;
    void	*wall;
    void	*floor;
    int img_width;
    int img_height;
}	t_game_objs;

// POSITIONS OF PLAYER AND EXIT
typedef struct	s_game_positions
{
    int	player_row;
    int	player_col;
	int	exit_row;
    int	exit_col;
}	t_game_positions;

// GAME DATA OF THE OBJECTS INSIDE THE MATRICE (INTERNAL)
typedef struct	s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_enemy;
	int	count_wall;
	int	count_empty;
    int count_movements;
    int endgame;
}	t_game_data;

// GAME RESOLUTIONS 
typedef struct	s_game_resolutions
{
    int	settings_map_width;
    int	settings_map_height;
    char	*settings_name_window;
    char	*settings_name_map;
}	t_game_resolutions;

// GAME DATA OF MATRICE (EXTERN)
typedef struct s_map_data
{
	int	first_read_matrice;
	int	cols_matrice;
	int	rows_matrice;
	int	size_matrice;
	char	**matrice;
	t_game_resolutions resolutions;
	t_game_positions positions;
}	t_map_data;

// MAIN GAME CONTROLLER
typedef struct s_game_instance
{
	void *mlx_ptr;
	void *win_ptr;
	int argc_tmp;
	char **argv_tmp;
	t_map_data map_init;
	t_game_positions positions_init;
	t_game_data game_data;
	t_game_resolutions resolutions_init;
	t_game_objs game_objs;
}	t_game_instance;

// ------------------------------------------------------------------------------------- STARTS HERE
// Function to starts the game instance and initializes the necessary structures
int	main(int argc, char **argv);
// ------------------------------------------------------------------------------------- GAME INIT
// Function to initialize all structs in the game instance + malloc in objs
void	ft_struct_init(t_game_instance *game_init);
// Function to initializes the game window and sets the initial properties of the game
void	ft_initialize_game(t_game_instance *game_init);
// ------------------------------------------------------------------------------------- GAME EVENTS
// Function to check an event handler for keyboard input during the game
int	ft_check_keyboard(int key, t_game_instance *game_init);
// Function to free() and quit the program
int	ft_exit_program(t_game_instance *game_init);
// Function to free() and reset the game (start in the same point)
void	ft_reset_game(t_game_instance *game_init);
// ------------------------------------------------------------------------------------- MAP VALIDATIONS AND MAP DATA
// Function to open and read the map file
int	ft_open_map(char *map, t_game_instance *game_init);
// Function to count the map content for ft_calloc (reserved space to ft_read_map() function)
int	ft_read_count_map(char *map);
// Function to calculate the dimensions of the game map by counting the number of rows, columns and matrice
int	ft_map_dimensions(t_game_instance *game_init);
// Function to reads a map from a file, validates it, and sets it in the game instance
int	ft_read_map(int fd, t_game_instance *game_init);
// Function to checks if the map has a valid .ber extension and path/
int	ft_map_extension(char *map);
// Function to checks if the map is valid by calling three other functions and returning 1 if all are true, 0 otherwise
int	ft_is_valid_map(t_game_instance *game_init);
// Function to checks if the map is rectangular/square
int	ft_is_map_shape_valid(t_game_instance *game_init);
// Function to checks if the map is closed/surrounded by walls by checking if the borders of the map consist only of walls
int	ft_is_wall(t_game_instance *game_init);
// Function to counts the number of players, exits, collectibles, walls, and empty spaces on the map, and checks if the map has at least one player, one exit, and one collectible
int	ft_count_map_objects(t_game_instance *game_init);
// Function checks if the map has at least one player, one exit, and one collectible
int ft_have_requires(t_game_instance *game_init);
// ------------------------------------------------------------------------------------- GAME EVENTS/ACTIONS + GRAPHICS
// Function to sets up the game window and calls ft_map_draw to draw the game map (is the gear of the game)
void	ft_gameplay_start(t_game_instance *game_init);
// Function to takes a keyboard input and performs corresponding actions, such as moving the player character or resetting the game (+ call for function print in the shell)
void ft_events_pressed(t_game_instance *game_init, int column, int row);
// Function to prints the current number of movements on the terminal shell, but only if the number of movements has changed since the last time it was called
void	ft_print_shell(t_game_instance *game_init);
// Function to displays the player number of movements on screen
int ft_player_moves(t_game_instance *game_init);
// Function to frees all the memory allocated during the game and exits the program
int	ft_exit_program(t_game_instance *game_init);
// Function to frees all the memory allocated during the game and reset the program (in the point of start)
void	ft_reset_game(t_game_instance *game_init);
// Function to finds the player position and performs actions like moving the player or removing a collectible based on the block they're trying to move to, after the player presses a key
void ft_locate_player(t_game_instance *game_init);
// ------------------------------------------------------------------------------------- GRAPHICS + EVENTS
// Function to loads the different game images (player, collectibles, floor, exit, and walls) from image files (XPM format)
void ft_img_init(t_game_instance *game_init);
// Function to draws the game map on screen, placing each object (walls, floors, player, exit, and collectibles) in the correct position based on their coordinates in the matrice
int ft_map_draw(t_game_instance *game_init);
// Function to sets the image of an object in the corresponding cell on the game board
void	ft_set(t_game_instance *game_init, void *img, int width, int height);
// ------------------------------------------------------------------------------------- I WANT TO BREAK [FREE]
// Function to free the matrice[][]
void ft_free_map(t_game_instance *game_init);
// Function to free all images.xpm
void ft_free_img(t_game_instance *game_init);
// ------------------------------------------------------------------------------------- CUSTOM ERRORS MESSAGE
// Function to returns feedback for errors that are related to the initialization of the game
void	ft_error_init(int n);
// Function to returns feedback for errors that are related to the map
void	ft_error_map(int n);
// ------------------------------------------------------------------------------------- AUXILIARY FUNCTIONS
// Function to compares two strings character by character and returns the difference between the first two non-matching characters (in ASCII value)
int	ft_strcmp(const char *s1, const char *s2);
// Function to take the path, filter it and put in the game window
void	ft_print_name_window(t_game_instance *game_init, char *path);

#endif
