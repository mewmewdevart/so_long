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

// Uses get_next_line to read the file and check the map errors
int ft_open_map(char *map);

// Function to read the characters reserved in the map passed as a parameter and allocate memory for it
int	ft_read_map(char *map);

// Check if the map have the correct path and .ber extension
int	ft_map_extension(char *map);

// Check if the read file map have or not cols and rows 
//		+ check if have a rectangule format
int	ft_check_map(char *map, t_size_map *map_size);
int	ft_count_cols_rows(char *map, t_size_map *map_size);
int	ft_check_cols(t_size_map *map_size, int cols_count);

// Clear all structures of map before checking
t_map_content	ft_map_start(void);
// Function receives a string that represents a map and counts a number of distinct elements present in the map
t_map_content ft_map_composed(char *map);

// Verifies that the map contains the correct number of players, exits and collectibles
int ft_map_composed_valid(t_map_content *map_data);

// Prints a custom error message and exits the program
void	ft_error_map(char *local, int n);

#endif
