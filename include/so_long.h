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

typedef struct s_game_compass
{
    int player_row;
    int player_col;
	int exit_row;
    int exit_col;
} t_game_compass;

typedef struct s_map_objects_counts
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
}	t_map_objects_counts;

typedef struct s_game_resolutions
{
    int settings_map_width;
    int settings_map_height;
    //char *settings_name_window;
    //char *settings_name_map;
} t_game_resolutions;

typedef struct s_map_data
{
    int first_read_matrice;
    int cols_matrice;
    int rows_matrice;
    int size_matrice;
    char **matrice;
    t_game_resolutions resolutions;
} t_map_data;

typedef struct s_game_instance
{
    void *mlx_ptr;
    void *win_ptr;
    t_map_data map_init;
    t_game_compass compass;
    t_map_objects_counts objs_count;
    t_game_resolutions resolutions;
} t_game_instance;

int	main(int argc, char **argv);
void ft_initialize_game(int argc, char **argv);

int	ft_check_keyboard(int key, t_game_instance *game_init);
int	ft_close_program (t_game_instance *game_init);
void	ft_reset_game(t_game_instance *game_init);

int	ft_open_map(char *map, t_map_data *map_data);
int	ft_read_count_map(char *map);
int	ft_read_map(int fd, t_map_data *map_data);
int	ft_map_dimensions(t_map_data *map_data);
int	ft_map_extension(char *map);

int	ft_is_valid_map(t_map_data *data);
int	ft_is_map_shape_valid(t_map_data *map_data);
int	ft_is_wall(t_map_data *map_data);
int	ft_count_map_objects(t_map_data *map_data, t_map_objects_counts *counts);

void	free_map(t_map_data *map_data);

void	ft_error_init(int n);
void	ft_error_map(int n);

int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strchr_all_ocurrences(char *str, char ch);
int	ft_is_blank(const char *str);
int	ft_isspace(int c);

#endif
