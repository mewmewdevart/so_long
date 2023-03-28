/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:12:32 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Check if the all conditions is valid or not
int	ft_is_valid_map(t_game_instance *game_init)
{

	ft_printf("\n Eu entrei na função ft_is_valid\n");
	if (!(ft_count_map_objects(game_init)))
		return (0);
	if (!(ft_is_map_shape_valid(game_init)))
		return (0);
	if (!(ft_is_wall(game_init)))
		return (0);
	ft_printf("Eu sai da função ft_is_valid\n");
	return (1);
}

// Check if the map is rectangular or square
int	ft_is_map_shape_valid(t_game_instance *game_init)
{
	if (!&game_init->map_init || game_init->map_init.cols_matrice <= 0 ||game_init->map_init.rows_matrice <= 0)
		return (0); 
	if (game_init->map_init.size_matrice == 0)
		return (0);
	if (game_init->map_init.size_matrice % game_init->map_init.rows_matrice == 0 && game_init->map_init.size_matrice / game_init->map_init.rows_matrice == game_init->map_init.cols_matrice)
		return (1);
	return (0);
}

// Check if the map is closed/surrounded by walls
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
			if (i == 0 || j == 0 || i == game_init->map_init.rows_matrice - 1 || j == game_init->map_init.cols_matrice - 1)
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

//int	ft_count_map_objects(t_game_instance *game_init, t_game_data *game_data);
// Count map content and check if it has (1)E, 1(E) and >= 1(C)
int	ft_count_map_objects(t_game_instance *game_init)
{
	int	i;
	int	j;

	i = 0; //
	while (game_init->map_init.matrice[i] != NULL)
	{
		j = 0;
		while (game_init->map_init.matrice[i][j] != '\0')
		{
			if (game_init->map_init.matrice[i][j] == PLAYER)
				game_init->game_data.count_player++;
			else if (game_init->map_init.matrice[i][j] == EXIT)
				game_init->game_data.count_exit++;
			else if (game_init->map_init.matrice[i][j] == COLLECTIBLE)
				game_init->game_data.count_collectible++;
			else if (game_init->map_init.matrice[i][j] == WALL)
				game_init->game_data.count_wall++;
			else if (game_init->map_init.matrice[i][j] == EMPTY)
				game_init->game_data.count_empty++;
			else if (game_init->map_init.matrice[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (!(game_init->game_data.count_player == 1 && game_init->game_data.count_exit == 1 && game_init->game_data.count_collectible >= 1))
		return (0);
	return (1);
}
