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

typedef struct s_map_objects_counts
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
}	t_map_objects_counts;

typedef struct s_map_data
{
	int		first_read;
	int		size;
	int		rows;
	int		cols;
	char	**matrice;
}	t_map_data;

// Function to open and read the map file
int		ft_open_map(char *map);
// Function to read and count the map content for ft_calloc in the next function
int	ft_read_count_map(char *map);
int		ft_read_map(int fd, t_map_data *map_data);
// Function to counts the number of rows, columns and size in matrice
int ft_map_dimensions(t_map_data *map_data);

// Function to initializate and to be free
t_map_objects_counts	ft_initialize_data(void);
t_map_data	ft_initialize_map(void);
void	ft_initialize_map_data(t_map_data *map, t_map_objects_counts *data);
void free_map(t_map_data *data);

// Check if all conditions are valid
int		ft_is_valid_map(t_map_data *data);

// Check if the map is rectangular/square
int	ft_is_map_shape_valid(t_map_data *data);

// Check if the map is closed/surrounded by walls
int		ft_is_wall(t_map_data *data);

// Count if the map must contain 1 exit, 1 starting position, and at least 1 collectible
int	ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts);

// Check if the map has a valid .ber extension and path/
int		ft_map_extension(char *map);

#endif
