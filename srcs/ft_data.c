/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:52 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:53 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Clear all structures of map before checking
t_map_content	ft_map_start(void)
{
	t_map_content	map_data;

	map_data.count_player = 0;
	map_data.count_exit = 0;
	map_data.count_collectible = 0;
	map_data.count_wall = 0;
	map_data.count_empty = 0;
	return (map_data);
}

// Function receives a string that represents a map and counts
//		+ a number of distinct elements present in the map
t_map_content	ft_map_composed(char *map)
{
	t_map_content	map_content;
	int				i;

	if (!map)
	{
		map_content.count_player = -1;
		return (map_content);
	}
	i = -1;
	while (map[++i])
	{
		if (map[i] == PLAYER)
			map_content.count_player++;
		else if (map[i] == EXIT)
			map_content.count_exit++;
		else if (map[i] == COLLECTIBLE)
			map_content.count_collectible++;
		else if (map[i] == WALL)
			map_content.count_wall++;
		else if (map[i] == EMPTY)
		map_content.count_empty++;
	}
	return (map_content);
}

// Verifies that the map contains the correct number 
//			of players, exits and collectibles
int	ft_map_composed_valid(t_map_content *map_data)
{
	if (map_data->count_player != 1 || map_data->count_exit != 1
		|| map_data->count_collectible < 1)
	{
		ft_error_map("Invalid map!", 61);
		return (-1);
	}
	return (1);
}
