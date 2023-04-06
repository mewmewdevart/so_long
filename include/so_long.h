/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:21:47 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:51:14 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include "custom_letters.h"
# include <fcntl.h> // Read
# include <string.h> // Strerror

// Game Objects
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// Game Keywords
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

// Elements of Game
typedef struct s_game_objs
{
    void *player;
    void *player_left;
    void *player_right;
    void *player_down;
    void *player_up;

    void *collectible;

    void *exit_open;
    void *exit_close;

    void *wall;
    void *floor;

    int img_width;
    int img_height;
} t_game_objs;

typedef struct s_game_positions
{
    int player_row;
    int player_col;
	int exit_row;
    int exit_col;
} t_game_positions;

typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;

    int count_movements;
    int endgame;
}	t_game_data;

typedef struct s_game_resolutions
{
    int settings_map_width;
    int settings_map_height;
    char *settings_name_window;
    char *settings_name_map;
} t_game_resolutions;

typedef struct s_map_data
{
    int first_read_matrice;
    int cols_matrice;
    int rows_matrice;
    int size_matrice;
    char **matrice;
    t_game_resolutions resolutions;
    t_game_positions positions;
} t_map_data;

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
} t_game_instance;

// Function to open and read the map file
int	main(int argc, char **argv);
// Initializes the game based on the command line arguments
void ft_struct_init(t_game_instance *game_init);
void	ft_initialize_game(t_game_instance *game_init);
 void ft_struct_init(t_game_instance *game_init);
void ft_print_name_window(t_game_instance *game_init, char *path);

// Checks if any reserved [key/clicks] was pressed and performs the corresponding behavior
int	ft_check_keyboard(int key, t_game_instance *game_init);
int ft_exit_program(t_game_instance *game_init);
void	ft_reset_game(t_game_instance *game_init);

// Function to open and read the map file
int	ft_open_map(char *map, t_game_instance *game_init);
// Function to count the map content for ft_calloc and read the map content
int	ft_read_count_map(char *map);
int	ft_read_map(int fd, t_game_instance *game_init);
// Function to counts the number of rows, columns and size in matrice
int	ft_map_dimensions(t_game_instance *game_init);
// Check if the map has a valid .ber extension and path/
int	ft_map_extension(char *map);

// Check if all conditions are valid
int	ft_is_valid_map(t_game_instance *game_init);
int	ft_is_map_shape_valid(t_game_instance *game_init);
int	ft_is_wall(t_game_instance *game_init);
int	ft_count_map_objects(t_game_instance *game_init);

// Gameplay of the game : Calling for events
void	ft_gameplay_start(t_game_instance *game_init);

// Draw the elements inside the map
void ft_img_init(t_game_instance *game_init);
void ft_settings_draw(t_game_instance *game_init, void *image, int width, int height);
int ft_map_draw(t_game_instance *game_init);

// Movements on screens
void ft_events_pressed(t_game_instance *game_init, int column, int row);
void ft_locate_player(t_game_instance *game_init);
int ft_player_moves(t_game_instance *game_init);

//void	ft_free_map(t_game_instance **game_init);
void ft_free_map(t_game_instance *game_init);
void ft_free_img(t_game_instance *game_init);

// Displays an error message for problems related to map, game and graphics
void	ft_error_init(int n);
void	ft_error_map(int n);

// Auxiliary functions : Compares two strings, check all ocurrances and blank spaces
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strchr_all_ocurrences(char *str, char ch);
int	ft_is_blank(const char *str);
int	ft_isspace(int c);

#endif
