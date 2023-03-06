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


typedef struct s_size_map {
    int rows;
    int cols;
    char *matrice;
} t_size_map;


//Uses get_next_line to read the file and check the map errors
int	ft_map_open(char *map);

//Check if the map have the correct path and .ber extension
int	ft_map_extension(char *map);

//takes the map file and returns a struct containing the map information
//t_map *ft_data_map(char *map);

//Clear all structures of map before checking
t_map_content	ft_map_start(void);

//Check if the all content inside the map is valid
int ft_read_map(char *map);

//Check if the read file map have or not cols and rows 
//		+ check if have a rectangule format
int	ft_count_cols_rows(char *map, t_size_map *map_size);

//Checks if the map is closed by walls on its border
int	ft_check_walls(char *map);

//Checks if the map has the main elements to be a valid map
t_map_content ft_map_composed(char *map);
int	ft_map_composed_valid(t_map_content *map_layers);

//Count the all elements have inside the map
t_map_content	ft_map_composed(char *map);

//Prints a custom error message and exits the program
void	ft_error_map(char *local, int n);

#endif
