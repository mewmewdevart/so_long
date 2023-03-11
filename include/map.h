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
	int		rows;
	int		cols;
	char	*matrice;
	int		size;
}	t_map;

// Function to open and read the map file
int		ft_open_map(char *map);
int		ft_read_map(int fd, t_map *map_data);

// Functions to initialize the game
t_map_content	ft_initialize_data(void);
t_map	ft_initialize_map(void);
void	ft_initialize_map_data(t_map *map, t_map_content *data);

// Check if all conditions are valid
int		ft_is_valid_map(t_map *data);
// Check if the map is rectangular
int		ft_is_rectangular(t_map *data);
// Check if the map is closed/surrounded by walls
int		ft_is_wall(t_map *data);
// The map must contain 1 exit, 1 starting position, and at least 1 collectible
 int	ft_is_content(t_map *data);
// Check if the map has a valid .ber extension and path/
int		ft_map_extension(char *map);

#endif
