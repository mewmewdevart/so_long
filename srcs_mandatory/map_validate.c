/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 14:24:15 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to checks if the map is valid by calling three other
//	functions and returning 1 if all are true, 0 otherwise
int	ft_is_valid_map(t_game_instance *game_init)
{
	if (!(ft_count_map_objects(game_init)))
		return (0);
	if (!(ft_is_map_shape_valid(game_init)))
		return (0);
	if (!(ft_is_wall(game_init)))
		return (0);
	return (1);
}

// Function to checks if the map is rectangular/square
int	ft_is_map_shape_valid(t_game_instance *game_init)
{
	if (game_init->map_init.cols_matrice <= 0
		|| game_init->map_init.rows_matrice <= 0)
		return (0);
	if (game_init->map_init.size_matrice == 0)
		return (0);
	if (game_init->map_init.size_matrice % game_init->map_init.rows_matrice == 0
		&& game_init->map_init.size_matrice / game_init->map_init.rows_matrice
		== game_init->map_init.cols_matrice)
		return (1);
	return (0);
}

// Function to checks if the map is closed/surrounded by walls
// 	by checking if the borders of the map consist only of walls
int	ft_is_wall(t_game_instance *game_init)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_init->map_init.rows_matrice)
	{
		j = 0;
		while (j < game_init->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice
				- 1 || j == game_init->map_init.cols_matrice - 1)
			{
				if (game_init->map_init.matrice[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Function to counts the objects in the map and 
// checks if the map has at 1 player, 1 exit and >= collectible
int	ft_count_map_objects(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrice[++row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == PLAYER)
				game_init->game_data.count_player++;
			else if (game_init->map_init.matrice[row][column] == EXIT)
				game_init->game_data.count_exit++;
			else if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				game_init->game_data.count_collectible++;
			else if (game_init->map_init.matrice[row][column] == WALL)
				game_init->game_data.count_wall++;
			else if (game_init->map_init.matrice[row][column] == EMPTY)
				game_init->game_data.count_empty++;
			else if (game_init->map_init.matrice[row][column] != '\n')
				return (0);
			column++;
		}
	}
	return (ft_have_requires(game_init));
}

// Function checks if the map has at least one player, one exit,
//		and one collectible
int	ft_have_requires(t_game_instance *game_init)
{
	if (!(game_init->game_data.count_player == 1
			&& game_init->game_data.count_exit == 1
			&& game_init->game_data.count_collectible >= 1))
		return (0);
	return (1);
}
