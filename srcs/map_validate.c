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
int	ft_is_valid_map(t_map_data *data)
{
	t_map_objects_counts	counts = {0};

	ft_printf("\n Eu entrei na função ft_is_valid\n");
	if (!(ft_count_map_objects(data, &counts)))
		return (0);
	if (!(ft_is_map_shape_valid(data)))
		return (0);
	if (!(ft_is_wall(data)))
		return (0);
	ft_printf("Eu sai da função ft_is_valid\n");
	return (1);
}

// Check if the map is rectangular or square
int	ft_is_map_shape_valid(t_map_data *map_data)
{
	if (!map_data || map_data->cols_matrice <= 0 || map_data->rows_matrice <= 0)
		return (0);
	if (map_data->size_matrice == 0)
		return (0);
	if (map_data->size_matrice % map_data->rows_matrice == 0 && map_data->size_matrice / map_data->rows_matrice == map_data->cols_matrice)
		return (1);
	return (0);
}

// Check if the map is closed/surrounded by walls
int	ft_is_wall(t_map_data *map_data)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_data->rows_matrice)
	{
		j = 0;
		while (j < map_data->cols_matrice)
		{
			if (i == 0 || j == 0 || i == map_data->rows_matrice- 1 || j == map_data->cols_matrice - 1)
			{
				if (map_data->matrice[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Count map content and check if it has (1)E, 1(E) and >= 1(C)
int	ft_count_map_objects(t_map_data *map_data, t_map_objects_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->matrice[i] != NULL)
	{
		j = 0;
		while (map_data->matrice[i][j] != '\0')
		{
			if (map_data->matrice[i][j] == PLAYER)
				counts->count_player++;
			else if (map_data->matrice[i][j] == EXIT)
				counts->count_exit++;
			else if (map_data->matrice[i][j] == COLLECTIBLE)
				counts->count_collectible++;
			else if (map_data->matrice[i][j] == WALL)
				counts->count_wall++;
			else if (map_data->matrice[i][j] == EMPTY)
				counts->count_empty++;
			else if (map_data->matrice[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (!(counts->count_player == 1 && counts->count_exit == 1 && counts->count_collectible >= 1))
		return (0);
	return (1);
}
