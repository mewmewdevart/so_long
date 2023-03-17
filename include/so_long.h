/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:21:47 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/28 14:35:52 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "map.h"
# include "custom_letters.h"

# include <fcntl.h> // Read
# include <string.h> // Strerror

# define ESC 65307 // Keywords
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114 // The [r] key

//#include "../rscs/sprites/Player_idle/idleAnim_00.xpm"

typedef struct s_map_settings
{
	char *name_window;
	char *map_name;
	int width;
	int height;
} t_map_settings;

typedef struct s_game_instance
{
	void	*mlx;
	void	*window;
	int argc;
	char **argv;
	t_map_settings settings;
} t_game_instance;

// Filters path of the map name to use it as the window name
t_map_settings	ft_print_map_name(char *path);

// The main function of the program
int	main(int argc, char **argv);

// Initializes the game based on the command line arguments
void	ft_initialize_game(int argc, char **argv);

// Checks if the [R] key was pressed and resets the game if so
void ft_reset_game(t_game_instance *game);

// Checks if any reserved [key] was pressed and performs the corresponding behavior
int		ft_check_keyboard(int key, t_game_instance *game);

// Checks if the [X] button in the window was pressed, if yes the game is closed
int ft_close_program(t_game_instance *game);

// Displays an error message for problems related to map, game and graphics
void	ft_error_map(int n);
//void	ft_error_game(char *local, int n);
//void	ft_error_graphics(char *local, int n);

// Auxiliary functions : Compares two strings and check all ocurrances (ft_strrchr work)
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strchr_all_ocurrences(char *str, char ch);
int	ft_is_blank(const char *str);
int	ft_isspace(int c);

#endif
