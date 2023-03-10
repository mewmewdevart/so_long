/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:19 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/02 13:49:21 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct s_map_content
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
}	t_map_content;

typedef struct s_map {
    int rows;
    int cols;
    char *matrice;
	int size;
} t_map;

// Function to open and read the map file
int ft_open_map(char *map);
int ft_read_map(int fd, t_map *map_data);

// Functions to initialize the game
void ft_initialize(void);
t_map	ft_map_start_map(void);
t_map_content	ft_map_start_data(void);
int ft_read_matrice(t_map *map_data);

// Check if all conditions are valid
int ft_is_valid_map();
// Check if the map is rectangular
int is_rectangular(t_map *data);
int	ft_check_cols(int cols_count, t_map *data);
int	ft_count_cols_rows(t_map *data);

// Check if the map is closed/surrounded by walls
int is_wall(char *map);
// The map must contain 1 exit, 1 starting position, and at least 1 collectible
int is_content(char *map);
// Check if the map has a valid .ber extension and path/
int	ft_map_extension(char *map);

#endif
